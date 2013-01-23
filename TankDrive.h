#include "WPILib.h"

enum Rotation {
	CW,
	CCW
};

class TankDrive {
	Jaguar *leftFrontJaguar;
	Jaguar *leftBackJaguar;
	Jaguar *rightFrontJaguar;
	Jaguar *rightBackJaguar;
	
	float goalLeftSpeed;
	float goalRightSpeed;
	
public:
	TankDrive(int leftFront, int rightFront, int leftBack, int rightBack);
	
	void Move(float leftSpeed, float rightSpeed);
	
	void Update();
};
