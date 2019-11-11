#include "vex.h"


void TestAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Test");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.4.1s");
  StartVirtualField(9, 33, 0);

IntakesMove(1);
VisionGoTo(1, 5, 500000);

}