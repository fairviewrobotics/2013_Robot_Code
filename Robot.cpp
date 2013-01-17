#include "WPILib.h"

#include "Control.h"

class Robot : public SimpleRobot {
	Control control;

public:
	Robot(void) {
		puts("I'm a robot");
		while(true) {
			printf("%f\n", control.GetX(RIGHT));
			printf("%f\n\n", control.GetY(RIGHT));
			Wait(0.5);
		}
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
