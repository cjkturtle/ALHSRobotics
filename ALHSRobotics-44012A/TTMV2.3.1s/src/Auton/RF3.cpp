#include "vex.h"


void RF3(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Red Front 3");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.3.2");
  StartVirtualField(9, 120, 0);

  IntakesMove(-0.25); // Unfold Tray
  Sleep(250); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(4, 35); // Move forward 48 inches
  DistMove(12, 15);
  Sleep(500);
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DegTurn(-90, 50);
  IntakesMove(0.5);
  DistMove(10, 60);
  DistMove(8,15);
  Sleep(100);
  AllStop();

  DegTurn(-45, 40);
  DistMove(11, 50);
 
  IntakesMove(-0.5); // Turn on intakes
  Sleep(750);
  IntakesMove(0);
  VirtualField(); // Print updated location to virtual field
  DropStack(); // Drop the cube stack in the small goal zone
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  AllStop();
}
 /* DistMove(31, -40); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  DegTurn(135, 20); // Turn right 135 degrees
  VirtualField(); // Print updated location to virtual field

  DistMove(18, 40); // Move forward 24 inches
  VirtualField(); // Print updated location to virtual field
  DropStack(); // Drop the cube stack in the small goal zone
  */