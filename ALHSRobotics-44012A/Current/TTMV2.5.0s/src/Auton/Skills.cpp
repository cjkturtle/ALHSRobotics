#include "vex.h"


void Skills(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Skills");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.5.0s");
  Brain.Screen.printAt(151, 120, "Point Goal: 40");
  StartVirtualField(9, 120, 0);

   IntakesMove(-0.25); // Unfold Tray
  Sleep(500); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(42, 15); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DistMove(20, -30); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(-105, 20); // Left turn 95 degrees
  VirtualField(); // Print updated location to virtual field

  DistMove(18, 40); // Move forward 24 inches
  VirtualField(); // Print updated location to virtual field
  IntakesMove(0.25); // Turn on intakes
  DistMove(5, 20); // Keep moving 6 more inches
  VirtualField(); // Print updated location to virtual field
  Sleep(1250); // Wait 0.25 seconds
  IntakesMove(0); // Turn off intakes

  DistMove(13.5, -40); // Move backward 6 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(205, 20); // Turn right 200 degrees
  VirtualField(); // Print updated location to virtual field
  DistMove(16, -40); // Move backward 3 inches
  VirtualField(); // Print updated location to virtual field
  IntakesMove(0.5); // Turn on intakes
  Sleep(3000); // Keep intakes on for 3 seconds
  IntakesStop(); // Stop the intakes

  DistMove(18, 40); // Move backward 3 inches
  DegTurn(-105, 20); // Left turn 95 degrees
  DistMove(20, 30); // Move forward 24 inches
  IntakesMove(0.5);
  DistMove(8, 15); // Move forward 24 inches
  Sleep(1000);
  IntakesStop();
  DegTurn(205, 20); // Turn right 200 degrees
  IntakesMove(0.5); // Turn on intakes
  Sleep(3000); // Keep intakes on for 3 seconds
  IntakesStop(); // Stop the intakes

  DegTurn(50, 20);
  IntakesMove(.25);
  DistMove(12, 10);
  Sleep(400);
  IntakesStop();
  DegTurn(60, 20);
  DistMove(20, -20);
  IntakesMove(0.5); // Turn on intakes
  Sleep(3000); // Keep intakes on for 3 seconds
  IntakesStop(); // Stop the intakes
    
  /* // Stack 6.  
  DistMove(10, 30);
  VisionCube(1, 5, 5000, 10);
  DegTurn(205, 20);
  VisionGoal(3, 5, 5000, 10);
  IntakesMove(-0.25); // Turn on intakes
  Sleep(400);
  IntakesMove(0);
  VirtualField();
  DropStack();
  VirtualField();
  Sleep(200);
  AllStop();
  */
    // Stack 5 and continue.
  DegTurn(-10, 20);
  DegTurn(-105, 20);
  DistMove(24, 20);
  IntakesMove(-0.25); // Turn on intakes
  Sleep(400);
  IntakesMove(0);
  VirtualField();
  DropStack();
  VirtualField();
  Sleep(200);
  SwingToLocation(1);
  DistMove(10, -20);
  DegTurn(-50, 20);
  DistMove(40, 40); 
    
  IntakesMove(1); // Turn on intakes
  DistMove(42, 15); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  DegTurn(50, 20);
  DistMove(11,30);
  IntakesMove(-0.25); // Turn on intakes
  Sleep(400);
  IntakesMove(0);
  VirtualField();
  DropStack();
  Sleep(200);
  AllStop();
    
    
    
    
    
    


  
}