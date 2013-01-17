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
};
