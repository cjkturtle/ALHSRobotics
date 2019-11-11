#include "vex.h"
using namespace vex;

void robotInit(bool wifi){
  
  controllerStatus = 1;
  inBeta = true;
  gameStatus = 0;
  //Home();
  calibration();
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
  if(screenClock == 30000){
    Brain.Screen.clearScreen(); 
    Brain.Screen.printAt(2, 20, "LB Temp: %1.0f" " Percent", LB.temperature(vex::percentUnits::pct));
    Brain.Screen.printAt(2, 40, "RB Temp: %1.0f" " Percent", RB.temperature(vex::percentUnits::pct));   
    Brain.Screen.printAt(2, 60, "R4BL Temp: N/A"); //%1.0f" " Percent", R4BL.temperature(vex::percentUnits::pct));
    Brain.Screen.printAt(2, 80, "R4BR Temp: N/A"); //%1.0f" " Percent", R4BR.temperature(vex::percentUnits::pct)); 
    Brain.Screen.printAt(2, 100, "Tray Temp: %1.0f" " Percent", Swing.temperature(vex::percentUnits::pct));
    Brain.Screen.printAt(2, 120, "IntakeL Temp: %1.0f" " Percent", IntakeL.temperature(vex::percentUnits::pct));
    Brain.Screen.printAt(2, 140, "IntakeR Temp: %1.0f" " Percent", IntakeR.temperature(vex::percentUnits::pct));  
    Brain.Screen.printAt(2, 160, "Time: %1.0f" " Seconds", Brain.timer(vex::timeUnits::sec));
    Brain.Screen.printAt(200,200, "Battery: " "%1.0d" " Percent", Brain.Battery.capacity(vex::percentUnits::pct));
    Brain.Screen.printAt(2, 180, "Program: TTM_V2.4.1s");
    Brain.Screen.printAt(2, 240, "Tray Rotations: %1.0f", Swing.rotation(rotationUnits::deg));
    Brain.Screen.printAt(208, 240, " G: %1.0f", currentGyro);
    Brain.Screen.printAt(288, 240, "AX: %1.0f", currentAccelX);
    Brain.Screen.printAt(360, 240, "AY: %1.0f", currentAccelY);


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

    if(controllerStatus == 1){
      Brain.Screen.printAt(200, 220, "Driver Profile: Carter");
    }
    else if(controllerStatus == 2){
      Brain.Screen.printAt(200, 220, "Driver Profile: Other");
    }
    else{
      Brain.Screen.printAt(200, 220, "Driver Profile: Carter");
    }
  }

  else if(screenClock > 30000){
  screenClock = 0;
  }
    
  screenClock++;
}    

// Function to add vision sensor debugging information to the brain screen.

void FullScreen(){
  Vision1.takeSnapshot(G);  
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::green);    
    Brain.Screen.drawRectangle(250,2, 25,25);
    Brain.Screen.setFillColor(vex::color::transparent);
    vex::task::sleep(50);
  }
  Vision1.takeSnapshot(P);
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::purple);    
    Brain.Screen.drawRectangle(250, 37, 25,25);
    Brain.Screen.setFillColor(vex::color::transparent);
    vex::task::sleep(50);
  }
  Vision1.takeSnapshot(O);
  if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
    MainScreen();
    Brain.Screen.setFillColor(vex::color::orange);    
    Brain.Screen.drawRectangle(250, 72, 25,25);
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

void IntakesMove(double direction){
  IntakeL.spin(vex::directionType::rev, (100*direction) * intakeSpeed, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, (100*direction) * intakeSpeed, vex::velocityUnits::pct); 
}

// Function for keeping the intakes moving at a usable rate while not specifically moving.

void IntakesIdle(){
  IntakeL.spin(vex::directionType::rev, 100*intakeIdleSpeed, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, 100*intakeIdleSpeed, vex::velocityUnits::pct); 
}

void IntakesStop(){
  IntakeL.stop(brakeType::hold);
  IntakeR.stop(brakeType::hold); 
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
  Swing.spin(vex::directionType::rev, 100*slowTraySpeed, vex::velocityUnits::pct); //test dir
}

void SwingUp(){
  Swing.spin(vex::directionType::fwd, 100*traySpeed, vex::velocityUnits::pct); //test dir
}

// Function for moving they cube tray to either an upright position or to an angled position.

 void SwingToLocation(int location){
   if((location == 1) && (!swingLimit)){ //go up
    while(!SwingLimit.pressing() && !controllerUseStatus){
     Swing.spin(vex::directionType::fwd, 100*traySpeed,vex::velocityUnits::pct);
      if(SwingLimit.pressing()){
        Swing.stop();
      }
    }   
  }

  else if(location == 0){ //go down
    float dist = -430.; //test value
    int swingMotorCurrent = Swing.rotation(vex::rotationUnits::deg);
    bool swing = false;
    Swing.spin(vex::directionType::rev, 100*slowTraySpeed,vex::velocityUnits::pct);
    while(!swing && !controllerUseStatus){
      swingMotorCurrent = Swing.rotation(vex::rotationUnits::deg);
      Brain.Screen.printAt(2,2, "SML: %1000l", swingMotorCurrent);
      if(swingMotorCurrent <= dist){
        Swing.stop();
        swing = true;
      } 
    }
  }
  Swing.stop(brakeType::hold);
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
   if(location == 1){ //go mid
    R4BL.startRotateTo(360,vex::rotationUnits::deg, r4bSpeed, vex::velocityUnits::pct); //test value
    R4BR.rotateTo(360,vex::rotationUnits::deg, r4bSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
  else if(location == 0){ //go down
    R4BL.startRotateTo(0,vex::rotationUnits::deg, r4bSpeed, vex::velocityUnits::pct); //test value
    R4BR.rotateTo(0,vex::rotationUnits::deg, r4bSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
 }

 void DropStack(){
  SwingToLocation(0);
  IntakesMove(-0.5);
  Sleep(1000);
  DistMove(6, -6);
  Sleep(500);
  SwingToLocation(1);
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
    if(abs(leftMotorCurrent) >= dist){
      LB.stop();
      left = true;
    }
    if(abs(rightMotorCurrent) <= -dist){
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
  Brain.Screen.printAt(4,22, "BF1");

  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(2, 62, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,82, "BB1");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(2, 122, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,142, "RF1");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(2, 182, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(4,202, "RB1");

  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(330, 182, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(332,202, "Skills");

  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(102, 2, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(104,22, "BF3");

  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(102, 62, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(104,82, "BB5");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(102, 122, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(104,142, "RF3");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(102, 182, 60, 40);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(104,202, "RB5");
}

void AutonSelector(int selectorState){
  
  AutonSelectorScreenInit();
  //Brain.Screen.printAt(120,20, "Auton Selection: None");

  while(!Competition.isEnabled()){
    if(Brain.Screen.pressing()){
      int xPressPos = Brain.Screen.xPosition();
      int yPressPos = Brain.Screen.yPosition();
   
        if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 2) && (yPressPos <= 40)){
          autonStatus = 1;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Blue Front 1");
          selectorState--;
          break;
        }
        else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 62) && (yPressPos <= 102)){
          autonStatus = 2;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Blue Back 1");
          selectorState--;
          break;
        }
        else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 122) && (yPressPos <= 162)){
          autonStatus = 3;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Red Front 1");
          selectorState--;
          break;
        }
        else if((xPressPos >= 2) && (xPressPos <= 60) && (yPressPos >= 182) && (yPressPos <= 222)){
          autonStatus = 4;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Red Back 1");
          selectorState--;
          break;
        }
        else if((xPressPos >= 330) && (xPressPos <= 390) && (yPressPos >= 182) && (yPressPos <= 222)){
          autonStatus = 9;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Skills");
          selectorState--;
          break;
        }
        //
         else if((xPressPos >= 102) && (xPressPos <= 160) && (yPressPos >= 2) && (yPressPos <= 40)){
          autonStatus = 5;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Blue Front 3");
          selectorState--;
          break;
        }
        else if((xPressPos >= 102) && (xPressPos <= 160) && (yPressPos >= 62) && (yPressPos <= 102)){
          autonStatus = 6;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Blue Back 5");
          selectorState--;
          break;
        }
        else if((xPressPos >= 102) && (xPressPos <= 160) && (yPressPos >= 122) && (yPressPos <= 162)){
          autonStatus = 7;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Red Front 3");
          selectorState--;
          break;
        }
        else if((xPressPos >= 102) && (xPressPos <= 160) && (yPressPos >= 182) && (yPressPos <= 222)){
          autonStatus = 8;
          Brain.Screen.clearScreen();
          Brain.Screen.printAt(120,20, "Auton Selection: Red Back 5");
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
  IntakeL.stop();
  IntakeR.stop();
}

// Function for homing all movable parts.

void Home(){
  SwingToLocation(1);
  //R4BToLocation(0);
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
        double velX = ((((Vision1.largestObject.originX) + ((Vision1.largestObject.width+1)/2)) - 158.5)*0.3165);
        //double velY = ((((Vision1.largestObject.originY) + ((Vision1.largestObject.height+1)/2)) - 106.5)*-0.3165); //190 //185.25

        LB.spin(vex::directionType::fwd, ((50 + velX)/2) * .5, vex::velocityUnits::pct);
        RB.spin(vex::directionType::rev, ((50 - velX)/2) * .5, vex::velocityUnits::pct);
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

void ControllerStatusPoll(){
  if(Competition.isDriverControl()){
    if(
      Controller.ButtonA.pressing() ||
      Controller.ButtonB.pressing() ||
      Controller.ButtonX.pressing() ||
      Controller.ButtonY.pressing() ||
      Controller.ButtonUp.pressing() ||
      Controller.ButtonRight.pressing() ||
      Controller.ButtonDown.pressing() ||
      Controller.ButtonLeft.pressing() ||
      Controller.ButtonL1.pressing() ||
      Controller.ButtonL2.pressing() ||
      Controller.ButtonR1.pressing() ||
      Controller.ButtonR2.pressing() ||
      (Controller.Axis1.position() > threashold) ||
      (Controller.Axis2.position() > threashold) ||
      (Controller.Axis3.position() > threashold) ||
      (Controller.Axis4.position() > threashold)){

        controllerUseStatus = true;
      }
    else{
      controllerUseStatus = false;
    }
  }
}

void calibration(){
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

void GyroTurn(int speed, int degrees){
    int current = get_current();
    //int dif = calcDif(degrees, current);
    int dir = calcDir(degrees, current);
    bool done = false;
    int newCurrent;
    int newDif;
    int newDir;
    while(!done){
        newCurrent = get_current();
        newDir = calcDir(degrees, newCurrent);
        newDif = calcDif(degrees,newCurrent);
        if(newDir != dir || newCurrent == degrees){
            done = true;
        }
        if(!done){
        LB.spin(vex::directionType::fwd,speed * dir,vex::velocityUnits::pct);
        RB.spin(vex::directionType::rev, speed * dir, vex::velocityUnits::pct);
        }
    }
    LB.stop(vex::brakeType::brake);
    RB.stop(vex::brakeType::brake);
}

void GyroCurrent(){
  int c = Gyro.value(vex::rotationUnits::deg) + 360;
  currentGyro = c%360;

}

void AccelCurrent(){
currentAccelX = AccelX.value(vex::percentUnits::pct);
currentAccelY = AccelY.value(vex::percentUnits::pct);
//velocityX = (AccelX.value(vex::analogUnits::mV) * moveTime);  //Need timers each time the robot moves
//velocityY = (AccelY.value(vex::analogUnits::mV) * moveTime);
//distanceX = (velocityX*moveTime);
//distanceY = (velocityY*moveTime);
}

void CalcMotionData(){
    bool collisionLeft = false;
    bool collisionRight = false;
    bool collisionFront = false;
    bool collisionBack = false;
    
    if(currentAccelX > 20){
        collisionFront = true;
    }
    else if(currentAccelX > -20){
        collisionBack = true;
    }
    else if(currentAccelX < 20){
        collisionLeft = true;
    }
    else if(currentAccelX < -20){
        collisionRight = true;
    }
    else{
    collisionLeft = false;
    collisionRight = false;
    collisionFront = false;
    collisionBack = false;
    }
}