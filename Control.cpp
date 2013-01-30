#include "Control.h"

Control::Control() {
	joystick = new Joystick(1);
}

// The axes are calibrated because they only go up to 0.6-0.7
float Control::GetX(Stick stick) {
	if(stick == RIGHT) {
		return -joystick->GetX()/0.65f;
	} else {
		return -joystick->GetRawAxis(5)/0.65f;
	}
}
float Control::GetY(Stick stick) {
	if(stick == RIGHT) {
		return -joystick->GetY()/0.65f;
	} else {
		return -joystick->GetRawAxis(3)/0.65f;
	}
}

bool Control::GetButton(int i) {
	return joystick->GetRawButton(i);
}
