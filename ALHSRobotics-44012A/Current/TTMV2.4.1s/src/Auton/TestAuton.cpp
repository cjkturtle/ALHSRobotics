#include "vex.h"


void TestAuton(){
  
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.printAt(151, 80, "Auton: Test");
  Brain.Screen.printAt(151, 100, "File: TTM_V2.4.1s");
  StartVirtualField(9, 120, 0);

  VisionGoTo(2, 5, 50000, 10);
  VisionGoTo(1, 5, 50000, 10);
  VisionGoTo(1, 5, 50000, 10);
  VisionGoTo(3, 5, 50000, 10);
/*

 IntakesMove(-0.25); // Unfold Tray
  Sleep(500); // Wait .5 seconds
  IntakesMove(1); // Turn on intakes
  DistMove(48, 30); // Move forward 48 inches
  IntakesStop(); // Stop the intakes
  VirtualField(); // Print updated location to virtual field

  DistMove(31, -60); // Move backward 31 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(-95, 20); // Left turn 95 degrees
  VirtualField(); // Print updated location to virtual field

  DistMove(20, 40); // Move forward 24 inches
  VirtualField(); // Print updated location to virtual field
  IntakesMove(0.5); // Turn on intakes
  DistMove(7, 20); // Keep moving 6 more inches
  VirtualField(); // Print updated location to virtual field
  Sleep(400); // Wait 0.25 seconds
  IntakesMove(0); // Turn off intakes

  DistMove(17.5, -40); // Move backward 6 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  DegTurn(205, 20); // Turn right 200 degrees
  VirtualField(); // Print updated location to virtual field
  DistMove(16, -40); // Move backward 3 inches
  VirtualField(); // Print updated location to virtual field
  IntakesMove(0.5); // Turn on intakes
  Sleep(3000); // Keep intakes on for 3 seconds
  IntakesStop(); // Stop the intakes
  DegTurn(-10, 20);
  
  DistMove(2.5, 25); // Move forward 3 inches
  VirtualField(); // Print updated location to virtual field
  Sleep(500);
  DegTurn(-105, 20); // Turn left 90 degrees
  VirtualField(); // Print updated location to virtual field
  IntakesMove(0.5); // Turn on intakes

  DistMove(12, 15); // Move forward 12 inches
  Sleep(400);
  IntakesStop(); // Stop the intakes
  DistMove(22, -30); // Move backward 12 inches
  VirtualField(); // Print updated location to virtual field

  DegTurn(95, 20); // Turn right 90 degrees
  VirtualField(); // Print updated location to virtual field
  //Brain.resetTimer(); 
  //Svec was here!
 // while(Brain.timer(vex::timeUnits::sec) <= 1.5){
  DistMove(21, 40);
 //} // Move forward 24 inches
  VirtualField(); // Print updated location to virtual field

  DegTurn(35, 20); // Turn right 45 degrees
  VirtualField(); // Print updated location to virtual field
 // Brain.resetTimer(); 
 // while(Brain.timer(vex::timeUnits::sec) <= 1.5){
  DistMove(10.5, 20);
// } // Move forward 18 inches
  IntakesMove(-0.25); // Turn on intakes
  Sleep(400);
  IntakesMove(0);
  VirtualField(); // Print updated location to virtual field
  DropStack(); // Drop the cube stack in the small goal zone
  VirtualField(); // Print updated location to virtual field
  Sleep(200);
  AllStop();
  */
}