#include "TankDrive.h"

#include <cassert>
#include <cmath>

TankDrive::TankDrive(int leftFront, int rightFront, int leftBack, int rightBack) {
	leftFrontJaguar = new Jaguar(leftFront);
	leftBackJaguar = new Jaguar(leftBack);
	rightFrontJaguar = new Jaguar(rightFront);
	rightBackJaguar = new Jaguar(rightBack);
}

void TankDrive::Move(float leftSpeed, float rightSpeed) {
	goalLeftSpeed = leftSpeed;
	goalRightSpeed = rightSpeed;
}

void TankDrive::Update() {
	leftFrontJaguar->SetSpeed(goalLeftSpeed);
	leftBackJaguar->SetSpeed(goalLeftSpeed);
	rightFrontJaguar->SetSpeed(goalRightSpeed);
	rightBackJaguar->SetSpeed(goalRightSpeed);
}
