void robotInit(bool wifi);
void MainScreen();
void FullScreen();
void Brake();
void IntakesMove(double direction);
void IntakesIdle();
void IntakesStop();
void ArmDown();
void ArmUp();
void ArmToLocation(int location);
void SwingDown();
void SwingUp();
void SwingToLocation(int location);
void R4BUp();
void R4BDown();
void R4BToLocation(int location);
void DropStack();
void DistMove(double distance, int speed);
void TimeMove(int speed, int time, bool stop);
void DegTurn(double degrees, int speed);
void AccelMove(int AccelDist, int EndSpeed);
void DecelMove(int DecelDist, int StartSpeed);
void SwingTurn(double degrees, int speed);
void GyroTurn(int speed, int degrees);
void MoveComplete(double distance, int speed);
void AutonSelectorScreenInit();
void AutonSelector(int selectorState);
void Sleep(double time);
void AllStop();
void Home();
void VisionInit(int color);
void VisionGoTo(int color, int minSize, int maxSize);

void FieldTemplate();
void RobotTemplate(double preMidX, double preMidY, double deg);
void StartVirtualField(int startX, int startY, int startRotation);
void VirtualField();

void calibration();
void GyroCurrent();

void CarterController();
void OtherController();

void BF1();
void BB1();
void RF1();
void RB1();
void BF3();
void BB5();
void RF3();
void RB5();
void Skills();
void TestAuton();