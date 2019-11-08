#include "vex.h"


void BlueLeftAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(151,80, "Auton: Blue Left");
  Brain.Screen.printAt(151, 100, "Program: TTM V2.1.0");
  StartVirtualField(24, 60, 0);
  DistMove(24, 60);
  //DegTurn(45, 20);
  VirtualField();
  Sleep(500);
  DegTurn(45, 20);
  VirtualField();
  Sleep(500);
  DistMove(24, 60);
  VirtualField();
  Sleep(500);
  DegTurn(45, 20);
  VirtualField();
  Sleep(500);
  DistMove(24, 60);
  VirtualField();
  Sleep(500);
  DegTurn(255, 20);
  VirtualField();
  Sleep(500);
  DistMove(24, 60);
  VirtualField();
  Sleep(500);
  DegTurn(-90, 20);
  VirtualField();
  Sleep(500);
  DistMove(24, 60);
  VirtualField();
}