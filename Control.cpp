#include "Control.h"

Control::Control() {
	joystick = new Joystick(1);
}

float Control::GetX(Stick stick) {
	if(stick == RIGHT) {
		return joystick->GetRawAxis(1);
	} else {
		return joystick->GetRawAxis(3);
	}
}
float Control::GetY(Stick stick) {
	if(stick == RIGHT) {
		return joystick->GetRawAxis(2);
	} else {
		return joystick->GetRawAxis(4);
	}
}
