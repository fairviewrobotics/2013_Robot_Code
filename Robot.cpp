#include <cmath>
#include "WPILib.h"

#include "Control.h"
#include "TankDrive.h"

class Robot : public SimpleRobot {
	Control control;
	
	TankDrive drive;
	
	Encoder *encoderLeft;
	Encoder *encoderRight;
	

	Compressor *compressor;
	Relay *shifterRelay;
	Solenoid *solenoid;
public:
	Robot(void) 
		: drive(1,3,2,4) {
		puts("I'm a robot");
		GetWatchdog().Kill();
		encoderLeft = new Encoder(1,2);
		encoderRight = new Encoder(3,4);
		encoderLeft->Start();
		encoderRight->Start();
		
		compressor = new Compressor(14,2);
		compressor->Start();
		
		//compressorRelay = new Relay(1, Relay::kForwardOnly);
		shifterRelay = new Relay(1, Relay::kForwardOnly);
		
		solenoid = new Solenoid(1);
	}

	void Autonomous(void) {
		puts("I'm autonomous");
	}

	void OperatorControl(void) {
		puts("I'm controlled");
		int it = 0;
		while(IsOperatorControl()) {
			++it;
			if(it%50000 == 0) {
				printf("%f\n", control.GetX(RIGHT));
				printf("%f\n", control.GetY(RIGHT));
				printf("%f\n", control.GetX(LEFT));
				printf("%f\n\n", control.GetY(LEFT));
	
				//printf("%d\n", compressor->GetPressureSwitchValue());
				printf("%f\n\n", encoderLeft->GetDistance());
			}
			//Did you hear about the circus fire? it was intents//
			/*if(control.GetButton(2)) {
				compressor->SetRelayValue(Relay::kOn);
				//compressorRelay->Set(Relay::kOn);
			} else {
				compressor->SetRelayValue(Relay::kOff);
				//compressorRelay->Set(Relay::kOff);
			}*/

			if(control.GetButton(1)) {
				solenoid->Set(true);
				shifterRelay->Set(Relay::kOn);
			} else {
				solenoid->Set(false);
				shifterRelay->Set(Relay::kOff);
			}
			
	
			drive.Move(control.GetY(LEFT), control.GetY(RIGHT));
			//drive.Rotate(abs(control.GetX(LEFT)), control.GetX(LEFT) > 0 ? CW : CCW);
			drive.Update();
		}
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
