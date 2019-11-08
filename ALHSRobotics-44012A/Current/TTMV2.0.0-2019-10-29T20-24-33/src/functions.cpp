#include "vex.h"
using namespace vex;

void robotInit(bool wifi){
  
  gameStatus = 0;
  Home();
  if(wifi){
    Vision1.setWifiMode(vex::vision::wifiMode::on);
    wifiMode = 1;
  }
  else{
    Vision1.setWifiMode(vex::vision::wifiMode::off);
    wifiMode = 0; 
  }
  AutonSelector(1);
}

void MainScreen(){ 
  Brain.Screen.clearScreen(); 
  Brain.Screen.printAt(2, 20, "LB Temp: %1.0f" " Percent", LB.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 40, "RB Temp: %1.0f" " Percent", RB.temperature(vex::percentUnits::pct));   
  Brain.Screen.printAt(2, 60, "R4BL Temp: %1.0f" " Percent", R4BL.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 80, "R4BR Temp: %1.0f" " Percent", R4BR.temperature(vex::percentUnits::pct)); 
  Brain.Screen.printAt(2, 100, "Tray Temp: %1.0f" " Percent", Swing.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 120, "IntakeL Temp: %1.0f" " Percent", IntakeL.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 140, "IntakeR Temp: %1.0f" " Percent", IntakeR.temperature(vex::percentUnits::pct));  
  Brain.Screen.printAt(2, 160, "Time: %1.0f" " Seconds", Brain.timer(vex::timeUnits::sec));
  Brain.Screen.printAt(2, 240, "screenToggle: %1.0d", screenStatus);
  Brain.Screen.printAt(200,200, "Battery: " "%1.0d" " Percent", Brain.Battery.capacity(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 180, "Program: TTM V2.1.0");
  
  if(wifiMode == 1){
    Brain.Screen.printAt(2,220, "Wifi Mode: Enabled");
  }
  else{
    Brain.Screen.printAt(2,220, "Wifi Mode: Disabled");
  } 
  if(gameStatus == 1){
    Brain.Screen.printAt(2,200, "Mode: Driver");
  }
  else if(gameStatus == 2){
    Brain.Screen.printAt(2,200, "Mode: Autonomus");
  }
  else { 
    Brain.Screen.printAt(2,200, "Mode: Idle");
  }
}    

// Function to add vision sensor debugging information to the brain screen.

void FullScreen(){
  Vision1.takeSnapshot(G);  
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::green);    
    Brain.Screen.drawRectangle(200,2, 25,25);
    Brain.Screen.setFillColor(vex::color::transparent);
    vex::task::sleep(50);
  }
  Vision1.takeSnapshot(P);
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::purple);    
    Brain.Screen.drawRectangle(226,2, 25,25);
    Brain.Screen.setFillColor(vex::color::transparent);
    vex::task::sleep(50);
  }
  Vision1.takeSnapshot(O);
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::orange);    
    Brain.Screen.drawRectangle(256,2, 25,25);
    Brain.Screen.setFillColor(vex::color::transparent);
    vex::task::sleep(50);
  }
  else{
  MainScreen();
    }
}

void Brake(){
  LB.stop(vex::brakeType::brake);
  RB.stop(vex::brakeType::brake); 
}

void IntakesMove(int direction){
  IntakeL.spin(vex::directionType::rev, (100*direction) * intakeSpeed, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, (100*direction) * intakeSpeed, vex::velocityUnits::pct);
}

// Function for keeping the intakes moving at a usable rate while not specifically moving.

void IntakesIdle(){
  //if(IntakeL.torque(Nm)){
  IntakeL.spin(vex::directionType::rev, 100*intakeIdleSpeed, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, 100*intakeIdleSpeed, vex::velocityUnits::pct); 
  //}
}


/*
void ArmDown(){
  Arm.spin(vex::directionType::fwd, 100*armSpeed, vex::velocityUnits::pct); //test dir
}

void ArmUp(){
  Arm.spin(vex::directionType::rev, 100*armSpeed, vex::velocityUnits::pct); //test dir
}


void ArmToLocation(int location = 0){ //go up
  if(location == 1){
    Arm.startRotateTo(0,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Arm.stop(vex::brakeType::hold);
  }
  else if(location == 0){ //go down
    Arm.startRotateTo(180,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Arm.stop(vex::brakeType::hold);
  }
}
*/

void SwingDown(){
  Swing.spin(vex::directionType::rev, 100*traySpeed, vex::velocityUnits::pct);
}

void SwingUp(){
  Swing.spin(vex::directionType::fwd, 100*traySpeed, vex::velocityUnits::pct); 
}

// Function for moving they cube tray to either an upright position or to an angled position.

 void SwingToLocation(int location){
   if((location == 1) && (!swingLimit)){ //go up
    Swing.startRotateTo(0,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
  else if(location == 0){ //go down
    Swing.startRotateTo(180,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
  else{
   Swing.stop(vex::brakeType::hold); 
  }
 }

void R4BUp(){
  R4BL.spin(directionType::fwd, 100*r4bSpeed, velocityUnits::pct);
  R4BR.spin(directionType::fwd, 100*r4bSpeed, velocityUnits::pct);
}

void R4BDown(){
  R4BL.spin(directionType::rev, 100*r4bSpeed, velocityUnits::pct);
  R4BR.spin(directionType::rev, 100*r4bSpeed, velocityUnits::pct);
}

 void R4BToLocation(int location){
   if(location == 1){ //go up
    R4BL.startRotateTo(0,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    R4BR.startRotateTo(0,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
  else if(location == 0){ //go down
    R4BL.startRotateTo(360,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    R4BR.startRotateTo(360,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
 }
 
// Function to move both drive motors for a given distance. Distance is to be provided in inches.

void DistMove(double distance, int speed){
  float dist = (distance/(3*PI)) * 360 * 0.75;
  LB.resetRotation();
  RB.resetRotation();
  int leftMotorCurrent = LB.rotation(vex::rotationUnits::deg);
  int rightMotorCurrent = RB.rotation(vex::rotationUnits::deg);
  bool left = false;
  bool right = false;
  LB.spin(vex::directionType::fwd, speed,vex::velocityUnits::pct);
  RB.spin(vex::directionType::rev, speed,vex::velocityUnits::pct);
  while(!right&&!left){
    leftMotorCurrent = LB.rotation(vex::rotationUnits::deg);
    rightMotorCurrent = RB.rotation(vex::rotationUnits::deg);
    Brain.Screen.printAt(2,2, "LML: %1000l", leftMotorCurrent);
    if(leftMotorCurrent >= dist){
      LB.stop();
      left = true;
    }
    if(rightMotorCurrent <= -dist){
      RB.stop();
      right = true;
    }
  }
  Brake();
  virtualFieldX = distance;		
  virtualFieldY = distance;	
}

// Function for moving both drive motors for a given length of time.

void TimeMove(int speed, int time, bool stop){
   LB.spin(vex::directionType::fwd, speed,vex::velocityUnits::pct);
   RB.spin(vex::directionType::rev, speed,vex::velocityUnits::pct);
   vex::task::sleep(time);
   if(stop){
     Brake(); 
   }
}

// Function for turning using a given number of degrees.

void DegTurn(double degrees, int speed){
    double deg = degrees/degConst;
    LB.startRotateFor(deg,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
    RB.rotateFor(deg,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
    virtualFieldRotation = degrees;
}

// Acceleration function.

void AccelMove(int AccelDist, int EndSpeed){
  int i = 1;
  while(i <= 10){
  int AccelSpeed = (EndSpeed/10);
  LB.spin(vex::directionType::fwd, (AccelSpeed * i),vex::velocityUnits::pct);
  RB.spin(vex::directionType::rev, (AccelSpeed * i),vex::velocityUnits::pct);
  i++;
  vex::task::sleep((AccelDist*accelConst)/10);
  
  }
}

// Deceleration function.

void DecelMove(int DecelDist, int StartSpeed){
  int i = 10;
  while((i <= 10) && (i >=0)){
  int AccelSpeed = (StartSpeed/10);
  LB.spin(vex::directionType::fwd, (AccelSpeed * i),vex::velocityUnits::pct);
  RB.spin(vex::directionType::rev, (AccelSpeed * i),vex::velocityUnits::pct);
  i--;
  vex::task::sleep((DecelDist*accelConst)/10);
  }
}

void SwingTurn(double degrees, int speed){
  double deg = degrees/degConst;
  if(degrees > 0){
    LB.rotateFor(deg*2,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
    RB.stop();
  }
  else if (degrees < 0){
    LB.stop();
    RB.rotateFor(deg*2,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  }
  else {
    Brake();
  }
}

// Function for driving with acceleration and deceleration included. 

void MoveComplete(double distance, int speed){
  double speedChangeDistance = (distance/10);
  AccelMove(distance, speed);
  DistMove(speedChangeDistance, speed);
  DecelMove(speedChangeDistance, speed);
}

void AutonSelectorScreenInit(){
  
  Brain.Screen.clearScreen();

  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(2, 2, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,22, "Blue Left");

  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(2, 62, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,82, "Blue Right");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(2, 122, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,142, "Red Left");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(2, 182, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,202, "Red Right");
}

void AutonSelector(int selectorState){
  
  AutonSelectorScreenInit();
  Brain.Screen.printAt(2,2, "Auton Selection: None");

 while(!Competition.isEnabled()){
    if(Brain.Screen.pressing()){
    int xPressPos = Brain.Screen.xPosition();
    int yPressPos = Brain.Screen.yPosition();
   
    if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 2) && (yPressPos <= 40)){
      autonStatus = 1;
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2,2, "Auton Selection: Blue Left");
      selectorState--;
      break;
    }
    else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 62) && (yPressPos <= 102)){
      autonStatus = 2;
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2,2, "Auton Selection: Blue Right");
      selectorState--;
      break;
    }
    else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 122) && (yPressPos <= 162)){
      autonStatus = 3;
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2,2, "Auton Selection: Red Left");
      selectorState--;
      break;
    }
    else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 182) && (yPressPos <= 222)){
      autonStatus = 4;
      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2,2, "Auton Selection: Red Right");
      selectorState--;
      break;
    }
    else{ 

    }

  Sleep(50);
}
}
}

void Sleep(double time){
  vex::task::sleep(time);
}

void AllStop(){
  Brake();
  Swing.stop();
  R4BL.stop();
  R4BR.stop();
  IntakesIdle();
}

// Function for homing all movable parts.

void Home(){
  while(!swingLimit){
    SwingToLocation(0);
  }
  while(!r4bLimit){
    R4BToLocation(0);
  }
}

// Initialization for the Vex vision sensor.

void VisionInit(int color){
  visionStatus = color;
  if (visionStatus == 1){
  detColor = 'G';
  }
  else if (color == 2){
  detColor = 'P';
  }
  else if (color == 3){
  detColor = 'O';
  }
  else{
  detColor = 'N';
  }
  Vision1.takeSnapshot(detColor);
}

// Function for traveling to the nearest object determined by the vision initilization function.

void VisionGoTo(int color, int minSize, int maxSize){
  MainScreen();
  int i = 0;
  while(!intakeTopStatus){
    if(color == 1){
      Vision1.takeSnapshot(G);
    }
    if(color == 2){
      Vision1.takeSnapshot(P);
    }
    if(color == 3){
      Vision1.takeSnapshot(O);
    }
    i++;
    Sleep(5);
  if(i == 5){    
    if(Vision1.largestObject.exists && Vision1.largestObject.width>=minSize && Vision1.largestObject.width<=maxSize){
        double velX = ((Vision1.largestObject.originX - 158.5)*0.6);
        double velY = ((Vision1.largestObject.originY - 185.25)*-0.6); //190

        LB.spin(vex::directionType::fwd, ((velY + velX)/2) * .5, vex::velocityUnits::pct);
        RB.spin(vex::directionType::rev, ((velY - velX)/2) * .5, vex::velocityUnits::pct);
        Sleep(50);
        i = 0;
    }
    else {
    Brake();
    i = 0;
    } 
   } 
  }
 }

void calibrate(){
  Gyro.startCalibration();
  while(Gyro.isCalibrating()){
      vex::task::sleep(100);
    }
}

 int get_current(){
    int c = Gyro.value(vex::rotationUnits::deg) + 360;
    c = c%360;
    return c;
}

int calcDif(int degrees, int current){
    int dif = abs(degrees - current);
    if(dif>180){
        dif = 360-dif;
    }
    return abs(dif);
}

int calcDir(int degrees, int current){
    int dif = calcDif(degrees, current);
    int dir;
    if((current+dif)%360==degrees){dir = 1;} else {dir = -1;}
    return dir;
}