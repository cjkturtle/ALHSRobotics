#include "vex.h"


void BB5(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Back 5");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(9, 120, 0);

  IntakesMove(-0.25); // Unfold Tray
  Sleep(500); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(48, 30); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DistMove(31, -50); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(-140, 30); // Left turn 95 degrees
  VirtualField(); // Print updated location to virtual field
  DistMove(11,40);
  IntakesMove(-0.25);
  Sleep(700);
  IntakesStop();
  SwingToLocation(0);
  IntakesMove(-0.5);
  Sleep(1000);
  DistMove(3, -6);
  DistMove(6, -100);
  SwingToLocation(1);
  AllStop();
}