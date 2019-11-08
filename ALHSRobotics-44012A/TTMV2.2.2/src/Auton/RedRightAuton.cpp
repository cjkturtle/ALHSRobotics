#include "vex.h"


void RedRightAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Right");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.2");
  StartVirtualField(12, 111, 270);
  DistMove(-24, 60);
  VirtualField();
  AllStop();
}