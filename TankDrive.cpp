#include "TankDrive.h"

#include <cassert>
#include <cmath>

TankDrive::TankDrive()
	: LEFT_PORT(1)
	, RIGHT_PORT(2) {
	leftJaguar = new Jaguar(LEFT_PORT);
	rightJaguar = new Jaguar(RIGHT_PORT);
}

void TankDrive::Move(float leftSpeed, float rightSpeed) {
	assert(leftSpeed >= -1.0f && leftSpeed <= 1.0f);
	assert(rightSpeed >= -1.0f && rightSpeed <= 1.0f);
	goalLeftSpeed = leftSpeed;
	goalRightSpeed = rightSpeed;
}

void TankDrive::Update() {
	leftJaguar->SetSpeed(leftGoalSpeed);
	rightJaguar->SetSpeed(rightGoalSpeed);
}
