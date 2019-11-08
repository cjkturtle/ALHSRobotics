#include "vex.h"


void BlueLeftAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Left");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.2");
  StartVirtualField(135, 60, 270);
  DistMove(-48, 60);
  VirtualField();
  AllStop();
}