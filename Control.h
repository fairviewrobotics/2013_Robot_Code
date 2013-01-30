#ifndef CONTROL_H
#define CONTROL_H

#include "WPILib.h"

enum Stick {
	RIGHT,
	LEFT
};

class Control {
	Joystick *joystick;
	
public:
	Control();
	
	float GetX(Stick stick);
	float GetY(Stick stick);
	
	bool GetButton(int i);
};

#endif
