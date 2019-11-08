#include "vex.h"


void RB5(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Back 5");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(12, 111, 270);
  
  IntakesMove(-0.25); // Unfold Tray
  Sleep(500); // Wait .5 seconds
  IntakesMove(0.5); // Turn on intakes
  DistMove(48, 15); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DistMove(31, -40); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(145, 20); // Left turn 95 degrees
  VirtualField(); // Print updated location to virtual field
  DistMove(8,20);
  IntakesMove(-0.5);
  Sleep(400);
  DropStack();
  SwingToLocation(1);
  AllStop();
}