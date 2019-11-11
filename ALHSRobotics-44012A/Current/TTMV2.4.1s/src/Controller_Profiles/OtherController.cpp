#include "vex.h"
using namespace vex;

int speedToggle = 1;

void OtherController(){
  Brain.resetTimer(); 
    gameStatus = 1;   
    while (true) {
    GyroCurrent();
    AccelCurrent();
    MainScreen();
        
        
      // Control setup for the drive speed.
      if((Controller.ButtonLeft.pressing()) || (Controller.ButtonRight.pressing())){speedToggle = 1;}
      else if(Controller.ButtonUp.pressing()){speedToggle = 2;}
      else if(Controller.ButtonDown.pressing()){speedToggle = 3;}
      else{}
         
      if(speedToggle == 2){Speed = 1.5;}
      else if (speedToggle == 3){Speed = 0.5;}
      else if(speedToggle == 1){Speed = 0.8;}
      else{}

         
      // Setup for split arcade controller drive.
        JRX = Controller.Axis1.value(); 
        JLY = Controller.Axis3.value();

      if(fabs(JRX) <= deadZone){JRX = 0;}
      if(fabs(JLY) <= deadZone){JLY = 0;}
      if(fabs(JRX) > threashold || fabs(JLY) > threashold){
        LB.spin(vex::directionType::fwd, ((JLY + JRX) / 2) * Speed, vex::velocityUnits::pct);
        RB.spin(vex::directionType::rev, ((JLY - JRX) / 2) * Speed, vex::velocityUnits::pct);
      }
      else{
        Brake(); 
      }


      // Setup code for the controls on the controller.


      // Intakes
      if(Controller.ButtonR1.pressing()){
        IntakesMove(1);
      }
      else if (Controller.ButtonR2.pressing()){
        IntakesMove(-0.5);
      }
      else{
      // IntakesIdle();
        IntakeL.stop(brakeType::hold);
        IntakeR.stop(brakeType::hold);
      }

      // Swing
      if(Controller.ButtonL1.pressing()){
        SwingUp();
      }
      else if(Controller.ButtonL2.pressing()){
        SwingDown();
      }
      else if(Controller.ButtonY.pressing()){ 
        SwingToLocation(1);
        Swing.stop(vex::brakeType::coast);
      }
      else if(Controller.ButtonX.pressing()){ 
        SwingToLocation(0);
        Swing.stop(vex::brakeType::coast);
      }
      else{
        Swing.stop(vex::brakeType::coast);
      }   


      // Control setup for the cube intakes.
      if(Controller.ButtonA.pressing()){
        DropStack();
      }


      //Sensors
      if(IntakeTop.pressing()){
        intakeTopStatus = true;
      }
      else{
        intakeTopStatus = false;
      }
      if(SwingLimit.pressing()){
        swingLimit = true;
        Swing.resetRotation();
      }
      else{
        swingLimit = false;
      }
      if((swingLimit) && (Controller.ButtonL1.pressing())){
      Controller.rumble(".-."); 
    } 
    else {

    }
    if(intakeTopStatus){
      Controller.rumble("...."); 
    } 
    else {

    }

  } 
}    
