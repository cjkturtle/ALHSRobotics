#include "vex.h"


void TestAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Test");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.1s");
  StartVirtualField(9, 120, 0);

  //VisionGoTo(1, 5, 5000);
  SwingToLocation(1);
}