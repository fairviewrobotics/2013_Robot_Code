#include "TransRotDrive.h"

#include <cassert>
#include <cmath>

TransRotDrive::TransRotDrive(int leftFront, int rightFront, int leftBack, int rightBack){
	leftFrontJaguar = new Jaguar(leftFront);
	leftBackJaguar = new Jaguar(leftBack);
	rightFrontJaguar = new Jaguar(rightFront);
	rightBackJaguar = new Jaguar(rightBack);
}

static float absMax(float a, float b) {
	return abs(a) > abs(b) ? a : b;
}

static float absMin(float a, float b) {
	return abs(a) < abs(b) ? a : b;
}

void TransRotDrive::Move(float speed) {
	goalSpeed = speed;
}

void TransRotDrive::Rotate(float speed, Rotation dir) {
	assert(speed >= 0.0f);
	goalRotationSpeed = speed;
	direction = dir;
}

void TransRotDrive::Update() {
	// Forwards
	if(goalSpeed > 0.0f) {
		if(direction == CW) {
			leftFrontJaguar->SetSpeed(absMax(goalSpeed, goalRotationSpeed));
			leftBackJaguar->SetSpeed(absMax(goalSpeed, goalRotationSpeed));
			rightFrontJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			rightBackJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
		} else {
			leftFrontJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			leftBackJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			rightBackJaguar->SetSpeed(absMax(goalSpeed, goalRotationSpeed));
			rightBackJaguar->SetSpeed(absMax(goalSpeed, goalRotationSpeed));
		}
	}
	// Backwards or pure rotation.
	else {
		if(direction == CW) {
			leftFrontJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			leftBackJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			rightFrontJaguar->SetSpeed(absMax(-goalSpeed, goalRotationSpeed));
			rightBackJaguar->SetSpeed(absMax(-goalSpeed, goalRotationSpeed));
		} else {
			leftFrontJaguar->SetSpeed(absMax(-goalSpeed, goalRotationSpeed));
			leftBackJaguar->SetSpeed(absMax(-goalSpeed, goalRotationSpeed));
			rightFrontJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			rightBackJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
		}
	}
}
