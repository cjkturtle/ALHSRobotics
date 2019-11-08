#include "vex.h"


void RedLeftAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Left");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.2");
  StartVirtualField(12, 60, 90);
  DistMove(-48, 60);
  VirtualField();
  AllStop();
}