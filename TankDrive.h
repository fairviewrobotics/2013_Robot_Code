#include "WPILib.h"

enum Rotation {
	CW,
	CCW
};

class TankDrive {
	Jaguar *leftJaguar;
	Jaguar *rightJaguar;
	
	float goalLeftSpeed;
	float goalRightSpeed;
	
	const int LEFT_PORT;
	const int RIGHT_PORT;
	
public:
	TankDrive();
	
	void Move(float leftSpeed, float rightSpeed);
	
	void Update();
};
