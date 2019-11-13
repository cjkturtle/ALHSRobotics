#include "vex.h"

using namespace vex;


void init(void) {
  robotInit(true);
}


void autoLoop() {
  Brain.resetTimer();
  gameStatus = 1;
  if(inBeta){ // If in beta, run uncommented autonomous no matter what autonomous selection is made.
    //BF1();
    //BB1();
    //RF1();
    //RB1();
    //BF3();
    //BB5();
    //RF3();
    //RB5();
    //Skills();
    TestAuton();
  }
  else{
    if((autonStatus == 1) && (Competition.isAutonomous())){
      BB1();
    }
    else if((autonStatus == 2) && (Competition.isAutonomous())){
      BB1();
    }
    else if((autonStatus == 3) && (Competition.isAutonomous())){
      RF1();
    }
    else if((autonStatus == 4) && (Competition.isAutonomous())){
      RB1();
    }
    else if((autonStatus == 9) && (Competition.isAutonomous())){
      Skills();
    }
    else if((autonStatus == 5) && (Competition.isAutonomous())){
      BF3();
    }
    else if((autonStatus == 6) && (Competition.isAutonomous())){
      BB5();
    }
    else if((autonStatus == 7) && (Competition.isAutonomous())){
      RF3();
    }
    else if((autonStatus == 8) && (Competition.isAutonomous())){
      RB5();
    }
    else{

    }
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

  if(LoadLight.value(analogUnits::pct) > 10){
    intakeLoadedStatus = true;
  }
  else{
    intakeLoadedStatus = false;
  }

}


void ControllerLoop() {
  if(controllerStatus == 1){
    CarterController();
  }    
  else if(controllerStatus == 2){
    OtherController();
  }
  else{
   CarterController();
  }
}


int main() {
  init();
  Competition.autonomous(autoLoop);
  Competition.drivercontrol(ControllerLoop);

  while (true) {
    Sleep(100);
  }
}