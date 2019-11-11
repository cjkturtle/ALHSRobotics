#include "vex.h"


void TestAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Test");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(9, 33, 0);

DistMove(12, 30);
VirtualField();
IntakesMove(1);
VisionGoTo(1, 5, 500000);




}