#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain;

vex::motor LB = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1);
vex::motor RB = vex::motor(vex::PORT3,vex::gearSetting::ratio18_1);
vex::motor IntakeL = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1);
vex::motor IntakeR = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1);
vex::motor Arm = vex::motor(vex::PORT5,vex::gearSetting::ratio36_1);
vex::motor Swing = vex::motor(vex::PORT6,vex::gearSetting::ratio36_1);
vex::motor R4BL = vex::motor(vex::PORT7,vex::gearSetting::ratio36_1);
vex::motor R4BR = vex::motor(vex::PORT8,vex::gearSetting::ratio36_1);

vex::controller Controller = vex::controller(vex::controllerType::primary);

vex::competition Competition = vex::competition();
//vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);


