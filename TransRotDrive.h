#ifndef TRANSROTDRIVE_H
#define TRANSROTDRIVE_H

#include "WPILib.h"

#include "Drive.h"

enum Rotation {
	CW,
	CCW
};

class TransRotDrive : public Drive {
	float goalSpeed;
	float goalRotationSpeed;
	
	Rotation direction;
	
public:
	TransRotDrive(int leftFront, int rightFront, int leftBack, int rightBack);
	
	void Move(float speed);
	
	void Rotate(float speed, Rotation dir);
	
	void Update();
};

#endif
