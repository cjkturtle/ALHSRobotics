#include "vex.h"


void RF3(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Front 3");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.4.0");
  StartVirtualField(9, 120, 0);

  IntakesMove(-0.25); // Unfold Tray
  Sleep(100); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(4, 35); // Move forward 48 inches
  DistMove(12, 15);
  Sleep(500);
  VirtualField(); // Print updated location to virtual field

  DegTurn(-90, 40);
  DistMove(10, 50);
  DistMove(8,15);
  Sleep(100);

  DegTurn(-52.5, 40);
  DistMove(13, 30);
 
  IntakesMove(-0.5); // Turn on intakes
  Sleep(850);
  IntakesStop();
  VirtualField(); // Print updated location to virtual field
  SwingToLocation(0);
  IntakesMove(-0.5);
  Sleep(1000);
  DistMove(3, -6);
  DistMove(6, -100);
  SwingToLocation(1);
  AllStop();
}