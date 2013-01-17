#include "WPILib.h"

enum Rotation {
	CW,
	CCW
};

class SingleStickDrive {
	Jaguar *leftJaguar;
	Jaguar *rightJaguar;
	
	float goalSpeed;
	float goalRotationSpeed;
	
	Rotation direction;
	
	const int LEFT_PORT;
	const int RIGHT_PORT;
	
public:
	SingleStickDrive();
	
	void Move(float speed);
	
	void Rotate(float speed, Rotation dir);
	
	void Update();
};
