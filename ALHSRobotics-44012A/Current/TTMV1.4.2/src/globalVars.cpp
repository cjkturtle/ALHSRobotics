int threashold = 10;
float PI =  3.14159265358979323;
double degConst = 0.32142857;
double accelConst = 28.6;
float Speed;
int armSpeed = 1;
int traySpeed = 1;
int intakeSpeed = 1;
double intakeIdleSpeed = 0.3; //test value
int r4bSpeed = 1;

int Timer1 = 1;
int screenToggle = 1; 
int screenStatus = 1;
int visionStatus = 0;
int gameStatus;
int autonStatus;
bool swingLimit = true; // Replace with sensor value.
bool r4bLimit = true; // Replace with sensor value.
bool intakeStatus = false; // Replace with sensor value.


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