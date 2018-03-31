
void setPistons(int pistonState) {
	if (pistonState == 0) {
		SensorValue[pistonOne] = 0;
		SensorValue[pistonTwo] = 0;
	}
	else {
		SensorValue[pistonOne] = 1;
		SensorValue[pistonTwo] = 1;
	}
}

void frictionDrumSpeed(int speed) {
	motor[frictionDrum2] = speed;
}

void liftSpeed(int speed) {
	motor[liftLeft] = speed;
	motor[liftRight] = speed;
}

void stopWheels() {
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
}

void mobileCaptureSpeed(int speed) {
	motor[mobileCapture] = speed;
}

void driveSpeed(int speed) {
	motor[frontLeft] = -speed;
	motor[backLeft] = -speed;
	motor[frontRight] = speed;
	motor[backRight] = speed;
}

void turnSpeed(int speed) {
	motor[frontLeft] = speed;
	motor[frontRight] = speed;
	motor[backRight] = -speed;
	motor[backLeft] = -speed;
}
