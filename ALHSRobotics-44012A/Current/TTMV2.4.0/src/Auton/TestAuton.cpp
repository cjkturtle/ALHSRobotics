#include "vex.h"


void TestAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Test");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(9, 33, 0);

DistMove(48, 30);
VirtualField();


}