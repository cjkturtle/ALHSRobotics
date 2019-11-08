#include "vex.h"
#include "Vision.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;

motor LB = motor(PORT1, ratio18_1);
motor RB = motor(PORT3, ratio18_1);
motor IntakeL = motor(PORT9, ratio18_1);
motor IntakeR = motor(PORT4, ratio18_1);
motor Arm = motor(PORT5, ratio36_1);
motor Swing = motor(PORT6, ratio36_1);
motor R4BL = motor(PORT7, ratio36_1);
motor R4BR = motor(PORT8, ratio36_1);

controller Controller = controller(primary);

competition Competition = competition();