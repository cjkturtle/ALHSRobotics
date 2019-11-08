#include "vex.h"


void BlueRightAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Right");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.2");
  StartVirtualField(135, 111, 90);
  DistMove(-24, 60);
  VirtualField();
  AllStop();
}