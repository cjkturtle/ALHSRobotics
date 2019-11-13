int threashold = 10;
float PI =  3.14159265358979323;
double degConst = 0.32142857;
double accelConst = 28.6;
float Speed;
int armSpeed = 1; //test value
double traySpeed = 0.6;
double slowTraySpeed = 0.3;
double intakeSpeed = 1;
double intakeIdleSpeed = 0.075;
int r4bSpeed = 1; //test value

int Timer1 = 1;
int Timer2 = 0; 
int screenClock = 0;
int screenToggle = 1; 
int screenStatus = 1;
int visionStatus = 0;
int wifiMode;
int gameStatus;
int autonStatus;
int controllerStatus;
bool controllerUseStatus;
bool swingLimit;
bool r4bLimit = true; // Replace with sensor value.
bool intakeTopStatus;
bool intakeLoadedStatus;
double virtualFieldRotation;
double virtualFieldX;
double virtualFieldY;
double currentGyro;
double currentAccelX;
double currentAccelY;
double velocityX;
double velocityY;
double distanceX;
double distanceY;
double moveTime;
 
char detColor;
double distToObject;

float inBeta;

float JRX;
float JLX;
float JRY;
float JLY;

int deadZone = 3;

void gVarsInit( void ) {
}