#ifndef DRIVE_H
#define DRIVE_H

#include "WPILib.h"

class Drive {
private:
	Jaguar *leftFrontJaguar;
	Jaguar *leftBackJaguar;
	Jaguar *rightFrontJaguar;
	Jaguar *rightBackJaguar;
	
protected:
	Drive(int leftFront, int rightFront, int leftBack, int rightBack);
	
	void SetLeftJaguars(float speed);
	void SetRightJaguars(float speed);
};

#endif
