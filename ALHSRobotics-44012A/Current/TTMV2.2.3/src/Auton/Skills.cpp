#include "vex.h"


void Skills(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Skills");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.2.3");
  StartVirtualField(12, 111, 270);
  //Reverse intake
  //sleep 0.5 sec
  //intake stop
  //move intake 1
  //move 20 inches at 20%

  IntakesMove(-0.5);
  Sleep(500);
  IntakesMove(1);
  DistMove(48, 20);
  IntakesStop();

  DistMove(31, -40);
  DegTurn(-95, 20);

  DistMove(24, 40);
  IntakesMove(1);
  DistMove(6, 20);
  Sleep(250);

  IntakesMove(0);

  DistMove(6, -40);
  DegTurn(200, 20);
  DistMove(3, -40);
  IntakesMove(1);
  Sleep(3000);
  IntakesStop();
  
  DistMove(3, 40);

  DegTurn(-75, 20);

  IntakesMove(1);

  DistMove(12, 40);

  IntakesStop();

  VirtualField();
  
}