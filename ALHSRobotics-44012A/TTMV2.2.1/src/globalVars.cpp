int threashold = 10;
float PI =  3.14159265358979323;
double degConst = 0.32142857;
double accelConst = 28.6;
float Speed;
int armSpeed = 1; //test value
double traySpeed = 0.3; //test value
int intakeSpeed = 1; //test value
double intakeIdleSpeed = 0.15; //test value
int r4bSpeed = 1; //test value

int Timer1 = 1;
int screenToggle = 1; 
int screenStatus = 1;
int visionStatus = 0;
int wifiMode;
int gameStatus;
int autonStatus;
bool swingLimit = true; // Replace with sensor value.
bool r4bLimit = true; // Replace with sensor value.
bool intakeTopStatus; // Replace with sensor value.
double virtualFieldRotation;
double virtualFieldX;
double virtualFieldY;
 


char detColor;
double distToObject;

float inBeta = true;

float JRX;
float JLX;
float JRY;
float JLY;

int deadZone = 3;

void gVarsInit( void ) {
}