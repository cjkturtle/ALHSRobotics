#include "vex.h"


void RedRightAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Back");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.3");
  StartVirtualField(12, 111, 270);
  DistMove(6, -60);
  Sleep(1000);
  DistMove(2, 60);
  VirtualField();
  
}