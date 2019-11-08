#include "vex.h"


void BB1(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Back 1");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(135, 60, 270);
  DistMove(6, -60);
  Sleep(1000);
  DistMove(2, 60);
  VirtualField();
}