/*vex-vision-config:begin*/
#include "v5.h"
#include "v5_vcs.h"
vex::vision::signature GSIG = vex::vision::signature (1, -7043, -5579, -6311, -4459, -2963, -3711, 3, 0);
vex::vision::signature PSIG = vex::vision::signature (2, 1801, 3277, 2539, 4831, 7119, 5975, 3, 0);
vex::vision::signature OSIG = vex::vision::signature (3, 6471, 9595, 8033, -1741, -1027, -1384, 3, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision Vision1 = vex::vision (vex::PORT10, 50, GSIG, PSIG, OSIG, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/