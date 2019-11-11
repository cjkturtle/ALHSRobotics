/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature G = vex::vision::signature (1, -7857, -6031, -6944, -3239, -1833, -2536, 3, 0);
vex::vision::signature P = vex::vision::signature (2, 1801, 3277, 2539, 4831, 7119, 5975, 3, 0);
vex::vision::signature O = vex::vision::signature (3, 6471, 9595, 8033, -1741, -1027, -1384, 1.7, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature N = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision Vision1 = vex::vision (vex::PORT5, 50, G, P, O, SIG_4, SIG_5, SIG_6, N);
/*vex-vision-config:end*/