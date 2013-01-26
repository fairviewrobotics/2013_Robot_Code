#include "TransRotDrive.h"

#include <cassert>
#include <cmath>

TransRotDrive::TransRotDrive(int leftFront, int rightFront, int leftBack, int rightBack) 
	: Drive(leftFront, rightFront, leftBack, rightBack) {
}

static float absMax(float a, float b) {
	return abs(a) > abs(b) ? a : b;
}

static float absMin(float a, float b) {
	return abs(a) < abs(b) ? a : b;
}

static float sign(float n) {
	return n < 0 ? -1 : 1;
}

void TransRotDrive::Move(float speed) {
	goalSpeed = speed;
}

void TransRotDrive::Rotate(float speed, Rotation dir) {
	direction = dir;
	goalRotationSpeed = speed;
}

void TransRotDrive::Update() {
	// Adding a deadzone
	const float deadzone = 0.1f;
	
	if(goalSpeed < deadzone && goalSpeed > -deadzone) {
		goalSpeed = 0.0f;
	} else {
		goalSpeed += sign(goalSpeed)*0.1f;
		goalSpeed /= 1.1f;
	}
	
	if(goalRotationSpeed < deadzone && goalRotationSpeed > -deadzone) {
		goalRotationSpeed = 0.0f;
	} else {
		goalRotationSpeed += sign(goalSpeed)*0.1f;
		goalRotationSpeed /= 1.1f;
	}
	
	// Forwards
	if(goalSpeed > 0.0f) {
		if(direction == CW) {
			SetLeftJaguars(absMax(goalSpeed, goalRotationSpeed));
			SetRightJaguars(goalSpeed - goalRotationSpeed);
		} else {
			SetLeftJaguars(goalSpeed - goalRotationSpeed);
			SetRightJaguars(absMax(goalSpeed, goalRotationSpeed));
		}
	}
	// Backwards or pure rotation.
	else {
		if(direction == CW) {
			SetLeftJaguars(goalSpeed + goalRotationSpeed);
			SetRightJaguars(absMax(goalSpeed, -goalRotationSpeed));
		} else {
			SetLeftJaguars(absMax(goalSpeed, -goalRotationSpeed));
			SetRightJaguars(goalSpeed + goalRotationSpeed);
		}
	}
}
