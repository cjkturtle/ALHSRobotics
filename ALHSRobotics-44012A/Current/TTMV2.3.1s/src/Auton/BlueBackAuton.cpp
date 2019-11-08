#include "vex.h"

void BlueBackAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Blue Back");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.1s");
  StartVirtualField(135, 120, 180);
   
  IntakesMove(-0.5); // Unfold Tray
  Sleep(500); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(48, 20); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DistMove(31, -40); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  DegTurn(-135, 20); // Turn left 135 degrees
  VirtualField(); // Print updated location to virtual field

  DistMove(18, 40); // Move forward 24 inches
  VirtualField(); // Print updated location to virtual field
  DropStack(); // Drop the cube stack in the small goal zone
}