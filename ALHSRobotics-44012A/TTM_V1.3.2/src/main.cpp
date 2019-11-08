#include "vex.h"
#include "Vision.h"

int threashold = 10;
float PI =  3.14159265358979323;
double degConst = 0.32142857;
double accelConst = 28.6;
float Speed;
int armSpeed = 1;
int traySpeed = 1;
int intakeSpeed = 1;
double intakeIdleSpeed = 0.3; //test value
int r4bSpeed = 1;

int Timer1 = 1;
int screenToggle = 1; 
int screenStatus = 1;
int visionStatus = 0;
int gameStatus;
bool swingLimit = true; // Replace with sensor value.
bool r4bLimit = true; // Replace with sensor value.
bool intakeStatus = false; // Replace with sensor value.


char detColor;
double distToObject;

float inBeta = true;

float JRX;
float JLX;
float JRY;
float JLY;

int deadZone = 3;


// Function to add debugging information to the brain screen.

void MainScreen(){ 
  Brain.Screen.clearScreen(); 
  Brain.Screen.printAt(2, 20, "LB Temp: %1.0f" " Percent", LB.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 40, "RB Temp: %1.0f" " Percent", RB.temperature(vex::percentUnits::pct));   
  Brain.Screen.printAt(2, 60, "R4bL Temp: %1.0f" " Percent", R4BL.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 80, "R4BR Temp: %1.0f" " Percent", R4BR.temperature(vex::percentUnits::pct)); 
  Brain.Screen.printAt(2, 100, "Arm Temp: %1.0f" " Percent", Arm.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 120, "IntakeL Temp: %1.0f" " Percent", IntakeL.temperature(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 140, "IntakeR Temp: %1.0f" " Percent", IntakeR.temperature(vex::percentUnits::pct));  
  Brain.Screen.printAt(2, 180, "Time: %1.0f" " Seconds", Brain.timer(vex::timeUnits::sec));
  Brain.Screen.printAt(2, 220, "screenToggle: %1.0d", screenToggle);
  Brain.Screen.printAt(2, 240, "screenToggle: %1.0d", screenStatus);
  Brain.Screen.printAt(200,200, "Battery: " "%1.0d" " Percent", Brain.Battery.capacity(vex::percentUnits::pct));
  Brain.Screen.printAt(2, 160, "Program: TTM V1.3.2");
  Brain.Screen.printAt(200,220, "Wifi Mode: ", Vision1.getWifiMode());
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
  IntakeL.spin(vex::directionType::fwd, (100*direction) * intakeSpeed, vex::velocityUnits::pct); //test dir
  IntakeL.spin(vex::directionType::rev, (100*direction) * intakeSpeed, vex::velocityUnits::pct); //test dir
}

// Function for keeping the intakes moving at a usable rate while not specifically moving.

void IntakesIdle(){
  IntakeL.spin(vex::directionType::fwd, 100*intakeIdleSpeed, vex::velocityUnits::pct); //test dir
  IntakeL.spin(vex::directionType::rev, 100*intakeIdleSpeed, vex::velocityUnits::pct); //test dir
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
  Arm.spin(vex::directionType::fwd, 100*traySpeed, vex::velocityUnits::pct); //test dir
}

void SwingUp(){
  Arm.spin(vex::directionType::rev, 100*traySpeed, vex::velocityUnits::pct); //test dir
}

// Function for moving they cube tray to either an upright position or to an angled position.

 void SwingToLocation(int location){
   if(location == 1){ //go up
    Swing.startRotateTo(0,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
  else if(location == 0){ //go down
    Swing.startRotateTo(180,vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
    Swing.stop(vex::brakeType::hold);
  }
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
    Brain.Screen.printAt(200,180, "LML: %1000l", leftMotorCurrent);
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
  while(!intakeStatus){
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

// Code for the autonomus control period.

void autoLoop(){
  Brain.resetTimer();
  gameStatus = 2;
  MainScreen();

  MoveComplete(72,100);
}

// Code for the driver control period.
    
void ControllerLoop(){
  Brain.resetTimer(); 
  gameStatus = 1;   
  while (true) {
      
    // Control setup for the drive speed.

    if(Controller.ButtonLeft.pressing()){Speed = 1.5;}
    else if (Controller.ButtonUp.pressing()){Speed = 0.6;}
    else{Speed = 1;}

    // Setup for the single joystick controller drive.

    JRX = Controller.Axis1.value(); 
    JRY = Controller.Axis2.value();

    if(fabs(JRX) <= deadZone){JRX = 0;}
    if(fabs(JRY) <= deadZone){JRY = 0;}

    if(fabs(JRX) > threashold || fabs(JRY) > threashold
  
  ){
      
      LB.spin(vex::directionType::fwd, ((JRY + JRX) / 2) * Speed, vex::velocityUnits::pct);
      RB.spin(vex::directionType::rev, ((JRY - JRX) / 2) * Speed, vex::velocityUnits::pct);
    }
    else{
      Brake(); 
    }
     
         
    // Setup code for the controls on the controller.
    

    // Control setup for the cube tray.

    if(Controller.ButtonL1.pressing()){
      Swing.spin(vex::directionType::fwd, 100*traySpeed, vex::velocityUnits::pct);;
    }
    else if (Controller.ButtonL2.pressing()){
      Swing.spin(vex::directionType::rev, 100*traySpeed, vex::velocityUnits::pct);;
    }
    if(Controller.ButtonY.pressing()){ 
      Swing.startRotateTo(0,vex::rotationUnits::deg, 100*armSpeed, vex::velocityUnits::pct); //test value
      Swing.stop(vex::brakeType::hold);
    }
    if(Controller.ButtonX.pressing()){ 
      Swing.startRotateTo(180, vex::rotationUnits::deg, 100*armSpeed, vex::velocityUnits::pct); //test value
      Swing.stop(vex::brakeType::hold);
    }
    else{
      Swing.stop(vex::brakeType::hold);
    }   
      
    // Control setup for the cube intakes.

    if(Controller.ButtonLeft.pressing()){
      IntakeL.spin(vex::directionType::fwd, 100*intakeSpeed, vex::velocityUnits::pct);
      IntakeR.spin(vex::directionType::fwd, 100*intakeSpeed, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonUp.pressing()){
      IntakeL.spin(vex::directionType::rev, 100*intakeSpeed, vex::velocityUnits::pct);
      IntakeR.spin(vex::directionType::rev, 100*intakeSpeed, vex::velocityUnits::pct);
    }
    else{
     IntakesIdle();
    }

    // Control setup for the reverse four bar.

    if(Controller.ButtonR1.pressing()){
      R4BL.spin(vex::directionType::fwd, 100*r4bSpeed, vex::velocityUnits::pct);
      R4BR.spin(vex::directionType::fwd, 100*r4bSpeed, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonR2.pressing()){
      R4BL.spin(vex::directionType::rev, 100*r4bSpeed, vex::velocityUnits::pct);
      R4BR.spin(vex::directionType::rev, 100*r4bSpeed, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonDown.pressing()){
      R4BL.startRotateTo(0, vex::rotationUnits::deg, 100*r4bSpeed, vex::velocityUnits::pct); //test value
      R4BR.startRotateTo(0, vex::rotationUnits::deg, 100*r4bSpeed, vex::velocityUnits::pct); //test value
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }
    else if(Controller.ButtonB.pressing()){
      R4BL.startRotateTo(360, vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
      R4BR.startRotateTo(360, vex::rotationUnits::deg, armSpeed, vex::velocityUnits::pct); //test value
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }
    else{
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }

    // Setup for controller screen during beta.
    if(inBeta){
      if (Controller.ButtonX.pressing()){
        screenToggle = 2;
      }

      if (screenToggle == 2){
        if (!Controller.ButtonX.pressing()){
          screenStatus= screenStatus * -1;
          screenToggle = 1;
        }
      }

      if (screenStatus == 1){
        Controller.Screen.clearScreen();
      }    
           
      if (screenStatus== -1){
        Controller.Screen.setCursor(1,1);
        Controller.Screen.print("LB: %1.0f", LB.temperature(vex::percentUnits::pct));
        Controller.Screen.newLine();
        Controller.Screen.print("RB: %1.0f", RB.temperature(vex::percentUnits::pct));
        Controller.Screen.newLine();
        Controller.Screen.print("R4BL: %1.0f", R4BL.temperature(vex::percentUnits::pct));
        Controller.Screen.setCursor(5,10);
        Controller.Screen.print("R4BR: %1.0f", R4BR.temperature(vex::percentUnits::pct));
        Controller.Screen.setCursor(1,10);
        Controller.Screen.print("Time: %1.0f", Brain.timer(vex::timeUnits::sec));
        Controller.Screen.setCursor(2,10); 
        Controller.Screen.print("Bat: " "%1.0d",Brain.Battery.capacity(vex::percentUnits::pct));
      }
    }       
    FullScreen();   
  } 
}    

int main() {
  Competition.autonomous(autoLoop);
  Competition.drivercontrol(ControllerLoop);
  while(true){
  Vision1.setWifiMode(vex::vision::wifiMode::on);
  }
}