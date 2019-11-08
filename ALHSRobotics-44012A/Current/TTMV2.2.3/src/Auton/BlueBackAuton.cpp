#include "vex.h"

void BlueRightAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Back");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.3");
  StartVirtualField(135, 111, 90);
  DistMove(6, -60);
  Sleep(1000);
  DistMove(2, 60);
  VirtualField();
}