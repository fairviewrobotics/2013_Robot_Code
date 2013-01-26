#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "WPILib.h"

#include "Drive.h"

class TankDrive : public Drive {
	float goalLeftSpeed;
	float goalRightSpeed;
	
public:
	TankDrive(int leftFront, int rightFront, int leftBack, int rightBack);
	
	void Move(float leftSpeed, float rightSpeed);
	
	void Update();
};

#endif
