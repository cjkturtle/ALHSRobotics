#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain;

vex::motor LB = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,true);
vex::motor RB = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,true);
vex::motor LiftL = vex::motor(vex::PORT5,vex::gearSetting::ratio36_1,true);
vex::motor LiftR = vex::motor(vex::PORT6,vex::gearSetting::ratio36_1,true);
vex::motor Intake = vex::motor(vex::PORT7,vex::gearSetting::ratio36_1,true);
vex::motor Top = vex::motor(vex::PORT8,vex::gearSetting::ratio18_1,true);

vex::controller Controller = vex::controller(vex::controllerType::primary);

vex::competition Competition = vex::competition();
//vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);


