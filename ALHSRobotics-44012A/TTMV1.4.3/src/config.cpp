#include "vex.h"


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

vex::vision::signature G = vex::vision::signature (1, -3419, -1943, -2681, -1377, -211, -794, 2.5, 0);
vex::vision::signature P = vex::vision::signature (2, -1, 477, 238, -1, 2317, 1158, 1, 0);
vex::vision::signature O = vex::vision::signature (3, 4617, 6219, 5418, -1465, -649, -1057, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT1, 50, G, P, O, SIG_4, SIG_5, SIG_6, SIG_7);
