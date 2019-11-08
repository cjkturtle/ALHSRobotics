#include "vex.h"
#include "Vision.h"

int t = 10;
int Timer1 = 1;
int ScreenToggle = 1; 
int ScreenStatus = 1;
int ArmSpeed = 1;
int SwingSpeed = 1;
int IntakeSpeed = 1;

float Beta = true;

float Speed;
float JRX;
float JLX;
float JRY;

int deadZone = 3;

/********************************************************************
AUTO
********************************************************************/

void autoLoop(){
while(true){
  Brain.Screen.clearScreen();
  Brain.resetTimer();
  Vision1.takeSnapshot(GSIG);
    if(Vision1.largestObject.exists && Vision1.largestObject.width>5){
      Brain.Screen.setFillColor(vex::color::green);    
      Brain.Screen.drawRectangle(2,2, 20,50);
      vex::task::sleep(50);
       Brain.Screen.clearScreen();    
  
  //}
  }
 }
}

/********************************************************************
CONTROLLER 
********************************************************************/
    
void ControllerLoop(){
  Brain.resetTimer();    
  while (true) {
      
    /********************************************************************
    JOYSTICK SPEED CONTROL
    *********************************************************************/            
 
    if(Controller.ButtonL1.pressing()){Speed = 1.5;}
    else if (Controller.ButtonUp.pressing()){Speed = 0.6;}
    else{Speed = 1;}

    /********************************************************************
    JOYSTICK 
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
      Swing.spin(vex::directionType::fwd, 100*SwingSpeed, vex::velocityUnits::pct);;
    }
    else if (Controller.ButtonL2.pressing()){
      Swing.spin(vex::directionType::rev, 100*SwingSpeed, vex::velocityUnits::pct);;
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

    //screens
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
      Brain.Screen.clearScreen(); 
      Brain.Screen.printAt(2, 20, "LB Temp: %1.0f" " Percent", LB.temperature(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 40, "RB Temp: %1.0f" " Percent", RB.temperature(vex::percentUnits::pct));   
      Brain.Screen.printAt(2, 60, "R4bL Temp: %1.0f" " Percent", R4BL.temperature(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 80, "R4BR Temp: %1.0f" " Percent", R4BR.temperature(vex::percentUnits::pct)); 
      Brain.Screen.printAt(2, 100, "Arm Temp: %1.0f" " Percent", Arm.temperature(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 120, "IntakeL Temp: %1.0f" " Percent", IntakeL.temperature(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 140, "IntakeR Temp: %1.0f" " Percent", IntakeR.temperature(vex::percentUnits::pct));  
      Brain.Screen.printAt(2, 200, "Time: %1.0f" " Seconds", Brain.timer(vex::timeUnits::sec));
      Brain.Screen.printAt(2, 220, "ScreenToggle: %1.0d", ScreenToggle);
      Brain.Screen.printAt(2, 240, "ScreenToggle: %1.0d", ScreenStatus);
      Brain.Screen.printAt(200,200, "Battery: " "%1.0d" " Percent",Brain.Battery.capacity(vex::percentUnits::pct));
      Brain.Screen.printAt(2, 180, "Program: TTM V0.9.3.4");
      
       
  } 
}    

int main() {
//while(true){
Competition.autonomous(autoLoop);
Competition.drivercontrol(ControllerLoop);
  // }
}
