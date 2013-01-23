#include "WPILib.h"

enum Rotation {
	CW,
	CCW
};

class TransRotDrive {
	Jaguar *leftFrontJaguar;
	Jaguar *leftBackJaguar;
	Jaguar *rightFrontJaguar;
	Jaguar *rightBackJaguar;
	
	float goalSpeed;
	float goalRotationSpeed;
	
	Rotation direction;
	
public:
	TransRotDrive(int leftFront, int rightFront, int leftBack, int rightBack);
	
	void Move(float speed);
	
	void Rotate(float speed, Rotation dir);
	
	void Update();
};
