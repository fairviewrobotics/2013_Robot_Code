#include "WPILib.h"

class Robot : public SimpleRobot {

public:
	Robot(void) {
		puts("I'm a robot");
	}

	void Autonomous(void) {
		puts("I'm autonomous");
	}

	void OperatorControl(void) {
		puts("I'm controlled");
	}
	
	void Disabled(void) {
		puts("I'm disabled");
	}
	
	void Test() {

	}
};

RobotBase *FRC_userClassFactory(void) {
	return new Robot();
}
extern "C" {
	int FRC_UserProgram_StartupLibraryInit(void) {
		RobotBase::startRobotTask((FUNCPTR)FRC_userClassFactory);
		return 0;
	}
}
