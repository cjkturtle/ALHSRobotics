#include "vex.h"


using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;

motor LB = motor(PORT1, ratio18_1);
motor RB = motor(PORT2, ratio18_1, false);
motor IntakeL = motor(PORT3, ratio18_1);
motor IntakeR = motor(PORT4, ratio18_1, false);
motor Arm = motor(PORT5, ratio36_1);
motor Swing = motor(PORT6, ratio36_1);
motor R4BL = motor(PORT7, ratio36_1);
motor R4BR = motor(PORT8, ratio36_1);

limit IntakeTop = limit(Brain.ThreeWirePort.B);
limit SwingLimit = limit(Brain.ThreeWirePort.A);
gyro Gyro = gyro(Brain.ThreeWirePort.C);
accelerometer AccelX = accelerometer(Brain.ThreeWirePort.D);
accelerometer AccelY = accelerometer(Brain.ThreeWirePort.E);

controller Controller = controller(primary);

competition Competition = competition();

vex::vision::signature G = vex::vision::signature (1, -7857, -6031, -6944, -3239, -1833, -2536, 3, 0);
vex::vision::signature P = vex::vision::signature (2, 1801, 3277, 2539, 4831, 7119, 5975, 3, 0);
vex::vision::signature O = vex::vision::signature (3, 6471, 9595, 8033, -1741, -1027, -1384, 3, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature N = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision Vision1 = vex::vision (vex::PORT10, 50, G, P, O, SIG_4, SIG_5, SIG_6, N);