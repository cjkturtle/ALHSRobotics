#include "vex.h"
#include "Vision.h"

using namespace vex;



void init(void) {
  robotInit();
}


void autoLoop(void) {
  Brain.resetTimer();
  gameStatus = 2;
  MainScreen();

  MoveComplete(72,100);
}


void ControllerLoop(void) {
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
    if(Controller.ButtonY.pressing()){ 
      SwingToLocation(1);
      Swing.stop(vex::brakeType::hold);
    }
    if(Controller.ButtonX.pressing()){ 
      SwingToLocation(0);
      Swing.stop(vex::brakeType::hold);
    }
    else{
      Swing.stop(vex::brakeType::hold);
    }   
      
    // Control setup for the cube intakes.

    if(Controller.ButtonLeft.pressing()){
      IntakesMove(1);
    }
    else if(Controller.ButtonUp.pressing()){
      IntakesMove(-1);
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
  robotInit();
  Competition.autonomous(autoLoop);
  Competition.drivercontrol(ControllerLoop);

  while (true) {
    Vision1.setWifiMode(vex::vision::wifiMode::on);
    Sleep(100);
  }
}
