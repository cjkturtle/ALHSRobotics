#include "vex.h"
using namespace vex;

void CarterController(){

Brain.resetTimer(); 
  gameStatus = 1;   
  while (true) {
  MainScreen();    
    // Control setup for the drive speed.

    if(Controller.ButtonLeft.pressing()){Speed = 1.5;}
    else if (Controller.ButtonUp.pressing()){Speed = 0.5;}
    else{Speed = 0.8;}

    // Setup for the single joystick controller drive.

      JRX = Controller.Axis1.value(); 
      JRY = Controller.Axis2.value();

    if(fabs(JRX) <= deadZone){JRX = 0;}
    if(fabs(JRY) <= deadZone){JRY = 0;}
    if(fabs(JRX) > threashold || fabs(JRY) > threashold){
      LB.spin(vex::directionType::fwd, ((JRY + JRX) / 2) * Speed, vex::velocityUnits::pct);
      RB.spin(vex::directionType::rev, ((JRY - JRX) / 2) * Speed, vex::velocityUnits::pct);
    }
    else{
      Brake(); 
    }
     
         
    // Setup code for the controls on the controller.
    

    // Control setup for the cube tray.

    if(Controller.ButtonL1.pressing()){
      SwingUp();
    }
    else if (Controller.ButtonL2.pressing()){
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

    if(Controller.ButtonRight.pressing()){
      IntakesMove(1);
    }
    else if(Controller.ButtonDown.pressing()){
      IntakesMove(-0.5);
    }
    else{
    // IntakesIdle();
     IntakeL.stop(brakeType::hold);
     IntakeR.stop(brakeType::hold);

    }

    // Control setup for the reverse four bar.

    if(Controller.ButtonR1.pressing()){
      R4BUp();
    }
    else if(Controller.ButtonR2.pressing()){
      R4BDown();
    }
    else if(Controller.ButtonA.pressing()){
      R4BToLocation(0);
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }
    else if(Controller.ButtonB.pressing()){
      R4BToLocation(1);
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }
    else{
      R4BL.stop(vex::brakeType::hold);
      R4BR.stop(vex::brakeType::hold);
    }

    if(Controller.ButtonR2.pressing()){
      DropStack();
    }

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

  /*if(LB.temperature((vex::percentUnits::pct) > 65) || ((RB.temperature(vex::percentUnits::pct) > 65)){
    Controller.Screen.clearScreen();
    Controller.Screen.print("DRIVE MOTOR OVERTEMP");
  }
      
  else{
          
  }
  */
  } 
}    
