#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "WPILib.h"

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

#endif
