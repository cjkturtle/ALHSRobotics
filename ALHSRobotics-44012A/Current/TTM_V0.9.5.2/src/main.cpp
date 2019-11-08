#include "vex.h"
#include "Vision.h"

int t = 10;
int Timer1 = 1;
int ScreenToggle = 1; 
int ScreenStatus = 1;
int VisionStatus = 0;
int GameStatus;

int ArmSpeed = 1;
int TraySpeed = 1;
int IntakeSpeed = 1;

char detcolor;
int maxsize; 
int minsize;
double DistToObject;

float Beta = true;

float PI =  3.14159265358979323;
float Speed;
float JRX;
float JLX;
float JRY;

int deadZone = 3;


//SETUP FUNCTIONS

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
      Brain.Screen.printAt(2, 220, "ScreenToggle: %1.0d", ScreenToggle);
      Brain.Screen.printAt(2, 240, "ScreenToggle: %1.0d", ScreenStatus);
      Brain.Screen.printAt(200,200, "Battery: " "%1.0d" " Percent",Brain.Battery.capacity(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 160, "Program: TTM V0.9.5.2");
      if(GameStatus == 1){
      Brain.Screen.printAt(2,200, "Mode: Driver");
      }
      else if(GameStatus == 2){
      Brain.Screen.printAt(2,200, "Mode: Autonomus");
      }
      else { 
      Brain.Screen.printAt(2,200, "Mode: Idle");
      }
  }    

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

void IntakesMove(int dir){
  IntakeL.spin(vex::directionType::fwd, 100*dir, vex::velocityUnits::pct);
  IntakeL.spin(vex::directionType::rev, 100*dir, vex::velocityUnits::pct);
}

void IntakesIdle(int Movespeed){
  IntakeL.spin(vex::directionType::fwd, 100*Movespeed, vex::velocityUnits::pct);
  IntakeL.spin(vex::directionType::rev, 100*Movespeed, vex::velocityUnits::pct);
}

void ArmDown(){
  Arm.spin(vex::directionType::fwd, 100*ArmSpeed, vex::velocityUnits::pct);
}

void ArmUp(){
  Arm.spin(vex::directionType::rev, 100*ArmSpeed, vex::velocityUnits::pct);
}

void TrayDown(){
  Arm.spin(vex::directionType::fwd, 100*TraySpeed, vex::velocityUnits::pct);
}

void TrayUp(){
  Arm.spin(vex::directionType::rev, 100*TraySpeed, vex::velocityUnits::pct);
}

void DistMove(double distance, int speed){
  float degrees = (distance/(3*PI)) * 360 * 0.75;
  LB.startRotateFor(degrees,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  RB.startRotateFor(-degrees,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
}

void TimeMove(int speed, int time, bool stop){
   LB.spin(vex::directionType::fwd, speed,vex::velocityUnits::pct);
   RB.spin(vex::directionType::rev, speed,vex::velocityUnits::pct);
   if(stop){
    LB.stop(vex::brakeType::brake);
    RB.stop(vex::brakeType::brake); 
   }
}

void DegTurn(double degrees, int speed){
    double deg = degrees/0.32142857;
  
    LB.startRotateFor(deg,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
    RB.startRotateFor(deg,vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
}

void Brake(){
LB.stop(vex::brakeType::brake);
RB.stop(vex::brakeType::brake); 
}

void Sleep(double time){
vex::task::sleep(time);
}

void InitVision(int color){
VisionStatus = color;
  if (VisionStatus == 1){
  detcolor = 'G';
  }
  else if (color == 2){
  detcolor = 'P';
  }
  else if (color == 3){
  detcolor = 'O';
  }
  else{
  detcolor = 'N';
  }
  Vision1.takeSnapshot(detcolor);
}


/********************************************************************
AUTO
********************************************************************/

void autoLoop(){
Brain.resetTimer();
GameStatus = 2;
  FullScreen(); 
  //DistMove(30.5, 50);
  DegTurn(180, 50);
  //Sleep(100);

}

/********************************************************************
CONTROLLER 
********************************************************************/
    
void ControllerLoop(){
Brain.resetTimer(); 
GameStatus = 1;   
  while (true) {
      
    /********************************************************************
    JOYSTICK SPEED CONTROL
    *********************************************************************/            
 
    if(Controller.ButtonL1.pressing()){Speed = 1.5;}
    else if (Controller.ButtonUp.pressing()){Speed = 0.6;}
    else{Speed = 1;}

    /********************************************************************
    JOYSTICK DRIVE
    ********************************************************************/

    JRX = Controller.Axis1.value(); 
    JRY = Controller.Axis2.value();

    if(fabs(JRX) <= deadZone){JRX = 0;}
    if(fabs(JRY) <= deadZone){JRY = 0;}

    if(fabs(JRX) > t || fabs(JRY) > t){
      
      LB.spin(vex::directionType::fwd, ((JRY + JRX) / 2) * Speed, vex::velocityUnits::pct);
      RB.spin(vex::directionType::rev, ((JRY - JRX) / 2) * Speed, vex::velocityUnits::pct);
      
      }
    else{
      LB.stop(vex::brakeType::brake);
      RB.stop(vex::brakeType::brake); 
    }
     
         
    /********************************************************************
    CONTROLLER BUTTONS
    ********************************************************************/
    

    //SWING
    if(Controller.ButtonL1.pressing()){
      Swing.spin(vex::directionType::fwd, 100*TraySpeed, vex::velocityUnits::pct);;
    }
    else if (Controller.ButtonL2.pressing()){
      Swing.spin(vex::directionType::rev, 100*TraySpeed, vex::velocityUnits::pct);;
    }
    else{
    Swing.stop(vex::brakeType::hold);
    }    


    //ARM
    if(Controller.ButtonR2.pressing()){
        Arm.spin(vex::directionType::rev,  100*ArmSpeed, vex::velocityUnits::pct);
    }       
    else if (Controller.ButtonR1.pressing()){
        Arm.spin(vex::directionType::fwd,  100*ArmSpeed, vex::velocityUnits::pct); 
    }

    else {
        Arm.stop(vex::brakeType::hold);
    }


    //INTAKE
    if(Controller.ButtonLeft.pressing()){
      IntakeL.spin(vex::directionType::fwd, 100*IntakeSpeed, vex::velocityUnits::pct);
      IntakeR.spin(vex::directionType::fwd, 100*IntakeSpeed, vex::velocityUnits::pct);
    }
    else if(Controller.ButtonUp.pressing()){
      IntakeL.spin(vex::directionType::rev, 100*IntakeSpeed, vex::velocityUnits::pct);
      IntakeR.spin(vex::directionType::rev, 100*IntakeSpeed, vex::velocityUnits::pct);
    }
    else{
      IntakeL.stop(vex::brakeType::hold);
      IntakeR.stop(vex::brakeType::hold);
    }


    //Controller Screen
    if(Beta){
      if (Controller.ButtonX.pressing()){
        ScreenToggle = 2;
      }

      if (ScreenToggle == 2){
        if (!Controller.ButtonX.pressing()){
          ScreenStatus = ScreenStatus * -1;
          ScreenToggle = 1;
        }
      }

      if (ScreenStatus == 1){
        Controller.Screen.clearScreen();
      }    
           
      if (ScreenStatus == -1){
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
//while(true){
Competition.autonomous(autoLoop);
Competition.drivercontrol(ControllerLoop);
  // }
}
