#include "Drive.h"

#include <cassert>
#include <cmath>

SingleStickDrive::SingleStickDrive()
	: LEFT_PORT(1)
	, RIGHT_PORT(2) {
	leftJaguar = new Jaguar(LEFT_PORT);
	rightJaguar = new Jaguar(RIGHT_PORT);
}

float AbsMax(float a, float b) {
	return abs(a) > abs(b) ? a : b;
}

float AbsMin(float a, float b) {
	return abs(a) < abs(b) ? a : b;
}

void Drive::Move(float speed) {
	assert(speed >= -1.0f && speed <= 1.0f);
	goalSpeed = speed;
}

void Drive::Rotate(float speed, Rotation dir) {
	assert(speed >= 0.0f && speed <= 1.0f);
	goalRotationSpeed = speed;
	direction = dir;
}

void Drive::Update() {
	// Forwards
	if(goalSpeed > 0.0f) {
		if(direction == CW) {
			leftJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
			rightJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
		} else {
			leftJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			rightJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
		}
	}
	// Backwards or pure rotation.
	else {
		if(direction == CW) {
			leftJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			rightJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
		} else {
			leftJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
			rightJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
		}
	}
}