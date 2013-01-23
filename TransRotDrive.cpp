#include "TransRotDrive.h"

#include <cassert>
#include <cmath>

TransRotDrive::TransRotDrive(int leftFront, int rightFront, int leftBack, int rightBack){
	leftFrontJaguar = new Jaguar(leftFront);
	leftBackJaguar = new Jaguar(leftBack);
	rightFrontJaguar = new Jaguar(rightFront);
	rightBackJaguar = new Jaguar(rightBack);
}

static float AbsMax(float a, float b) {
	return abs(a) > abs(b) ? a : b;
}

static float AbsMin(float a, float b) {
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
			leftFrontJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
			leftBackJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
			rightFrontJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			rightBackJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
		} else {
			leftFrontJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			leftBackJaguar->SetSpeed(goalSpeed - goalRotationSpeed);
			rightBackJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
			rightBackJaguar->SetSpeed(AbsMax(goalSpeed, goalRotationSpeed));
		}
	}
	// Backwards or pure rotation.
	else {
		if(direction == CW) {
			leftFrontJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			leftBackJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			rightFrontJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
			rightBackJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
		} else {
			leftFrontJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
			leftBackJaguar->SetSpeed(AbsMax(-goalSpeed, goalRotationSpeed));
			rightFrontJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
			rightBackJaguar->SetSpeed(-goalSpeed + goalRotationSpeed);
		}
	}
}
