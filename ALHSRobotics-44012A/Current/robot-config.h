vex::brain Brain;

vex::motor LF = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,true);
vex::motor LB = vex::motor(vex::PORT5,vex::gearSetting::ratio18_1,true);
vex::motor RF = vex::motor(vex::PORT3,vex::gearSetting::ratio18_1,true);
vex::motor RB = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,true);
vex::motor Stacker = vex::motor(vex::port5,vex::gearSetting::ratio36_1,true);
vex::motor IntakeL = vex::motor(vex::port6,vex::gearSetting::ratio36_1,true);
vex::motor IntakeR = vex::motor(vex::port6,vex::gearSetting::ratio36_1,true);

vex::controller Controller = vex::controller(vex::controllerType::primary);

vex::competition Competition = vex::competition();
//vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);
