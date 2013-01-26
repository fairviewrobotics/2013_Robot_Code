#include "TankDrive.h"

#include <cassert>
#include <cmath>

TankDrive::TankDrive(int leftFront, int rightFront, int leftBack, int rightBack)
	: Drive(leftFront, rightFront, leftBack, rightBack) {
	
}

void TankDrive::Move(float leftSpeed, float rightSpeed) {
	goalLeftSpeed = leftSpeed;
	goalRightSpeed = rightSpeed;
}

void TankDrive::Update() {
	SetLeftJaguars(goalLeftSpeed);
	SetRightJaguars(goalRightSpeed);
}
