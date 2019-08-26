#include "robot-config.h"

int t = 10;

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
 
 if(Controller.ButtonL1.pressing()){Speed = 1.3;}
 else if (Controller.ButtonUp.pressing()){Speed = 0.5;}
 else{Speed = 0.8;}

/********************************************************************
JOYSTICK 
********************************************************************/

 JRX = Controller.Axis1.value(); //Joystick Right X
 JLX = Controller.Axis4.value(); //Joystick Left X
 JRY = Controller.Axis2.value(); //Joystick Right Y
   
      if(fabs(JRX) || fabs(JRY) > t || fabs(JLX) > t){
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
         


//void screenLoop(){
   //while(true){
   Brain.Screen.clearScreen(); 
   Brain.Screen.printAt(2, 40, "LF Temp: %f" "%", LF.temperature(vex::percentUnits::pct));
   Brain.Screen.printAt(2, 80, "LB Temp: %f" "%", LB.temperature(vex::percentUnits::pct));   
   Brain.Screen.printAt(2, 120, "RF Temp: %f" "%", RF.temperature(vex::percentUnits::pct));
   Brain.Screen.printAt(2, 160, "RB Temp: %f" "%", RB.temperature(vex::percentUnits::pct)); 
    vex::task::sleep(1);  
 }

}
    
    int main() {
        autoLoop();
        ControllerLoop();
        //Competition.autonomous(autoLoop);
        //Competition.drivercontrol(ControllerLoop);
         //while(true){vex::task::sleep(100);}
}
                               
