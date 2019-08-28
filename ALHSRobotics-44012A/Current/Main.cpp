#include "robot-config.h"

int t = 10;
int Timer1 = 1;
int ScreenToggle = 1; 
int ScreenStatus = 1;

float Speed;
float JRX;
float JLX;
float JRY;


/********************************************************************
AUTO
********************************************************************/

void autoLoop(){
    
}
 
/********************************************************************
CONTROLLER 
********************************************************************/
    
void ControllerLoop(){
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
 JLX = Controller.Axis4.value();
 JRY = Controller.Axis2.value();
   
      if(fabs(JRX) > t || fabs(JRY) > t || fabs(JLX) > t){
        LF.spin(vex::directionType::fwd, ((JRY + JLX + JRX) / 2) * Speed, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, ((JRY + JLX - JRX) / 2) * Speed, vex::velocityUnits::pct);
        RF.spin(vex::directionType::fwd, ((JRY - JLX - JRX) / 2) * Speed, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, ((JRY - JLX + JRX) / 2) * Speed, vex::velocityUnits::pct);
        }
       else{
        LF.stop(vex::brakeType::brake);
        LB.stop(vex::brakeType::brake);
        RF.stop(vex::brakeType::brake);
        RB.stop(vex::brakeType::brake); 
        } 
         
/********************************************************************
CONTROLLER BUTTONS
********************************************************************/

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
    
Timer1++;
if(Timer1 == 10){        
    
    if (ScreenStatus == -1){
        Controller.Screen.setCursor(1,1);
        Controller.Screen.print("LF: %0.1f", LF.temperature(vex::percentUnits::pct));
        Controller.Screen.newLine();
        Controller.Screen.print("LB: %0.1f", LB.temperature(vex::percentUnits::pct));
        Controller.Screen.newLine();
        Controller.Screen.print("RF: %0.1f", RF.temperature(vex::percentUnits::pct));
        Controller.Screen.setCursor(1,10);
        Controller.Screen.print("RB: %0.1f", RB.temperature(vex::percentUnits::pct));
        }
             
   Brain.Screen.clearScreen(); 
   Brain.Screen.printAt(2, 40, "LF: %0.1f" "%", LF.temperature(vex::percentUnits::pct));
   Brain.Screen.printAt(2, 80, "LB Temp: %0.1f" "%", LB.temperature(vex::percentUnits::pct));   
   Brain.Screen.printAt(2, 120, "RF Temp: %0.1f" "%", RF.temperature(vex::percentUnits::pct));
   Brain.Screen.printAt(2, 160, "RB Temp: %0.1f" "%", RB.temperature(vex::percentUnits::pct)); 
   Brain.Screen.printAt(2, 200, "Timer: %0.1f", Brain.timer(vex::timeUnits::sec));
   Brain.Screen.printAt(2, 220, "ScreenToggle: %0.1d", ScreenToggle);
   Brain.Screen.printAt(2, 240, "ScreenToggle: %0.1d", ScreenStatus);
      
  }   
  if(Timer1 == 10){
  
    Timer1 = 1;  
    }
 }
}    

    int main() {
        autoLoop();
        ControllerLoop();
        //Competition.autonomous(autoLoop);
        //Competition.drivercontrol(ControllerLoop);
         //while(true){vex::task::sleep(100);}
}
                               
