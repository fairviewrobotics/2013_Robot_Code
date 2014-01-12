#include "Control.h"
#include <math.h>

Control::Control() {
	joystick = new Joystick(1);
}

// The axes are calibrated because they only go up to 0.6-0.7
float Control::GetX(Stick stick) {
	if(stick == LEFT) {
		return joystick->GetRawAxis(1);
	} else {
		return joystick->GetRawAxis(4);
	}
}

float Control::GetY(Stick stick) {
	if(stick == LEFT) {
		return Deadzone(-1.0*(joystick->GetRawAxis(2)),0.08);
	} else {
		return Deadzone(-1.0*(joystick->GetRawAxis(5)),0.08);
	}
}

float Control::Deadzone(float input, float threshold){
	if (fabs(input)<threshold)return 0.0;
	else return input;
	
}


bool Control::GetButton(int i) {
	return joystick->GetRawButton(i);
}
