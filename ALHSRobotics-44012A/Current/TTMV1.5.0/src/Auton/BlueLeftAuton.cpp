#include "vex.h"


void BlueLeftAuton(){

    Brain.Screen.printAt(200,240, "Auton: Blue Left");
    StartVirtualField(24, 60, 0);
    //DistMove(24, 60);
    DegTurn(15, 20);
    VirtualField();
    Sleep(1000);
    DistMove(24, 60);
    //VirtualField2();
    Sleep(1000);
    DegTurn(15, 20);
    VirtualField();
    //Sleep(500);
   // DistMove(24, 60);
    //VirtualField();
    
    
}