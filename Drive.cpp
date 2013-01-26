#include "Drive.h"

Drive::Drive(int leftFront, int rightFront, int leftBack, int rightBack) {
	leftFrontJaguar = new Jaguar(leftFront);
	leftBackJaguar = new Jaguar(leftBack);
	rightFrontJaguar = new Jaguar(rightFront);
	rightBackJaguar = new Jaguar(rightBack);
}

void Drive::SetLeftJaguars(float speed) {
	leftFrontJaguar->SetSpeed(speed);
	leftBackJaguar->SetSpeed(speed);
}

void Drive::SetRightJaguars(float speed) {
	rightFrontJaguar->SetSpeed(speed);
	rightBackJaguar->SetSpeed(speed);
}
