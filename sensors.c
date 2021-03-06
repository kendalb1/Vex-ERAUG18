#include "motion.h"

void driveRaw(int amount) {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	
	if (amount > 0) {
		// for driving forward
		driveSpeed(WHEELS_FORWARD * .5);
		while((SensorValue[liftEncoder] <= amount))
			wait1Msec(10); // let other tasks run
		driveSpeed(WHEELS_BACKWARD * .1); // kill the momentum
	}
	else {
		// for driving backward
		driveSpeed(WHEELS_BACKWARD * .5);
		while((SensorValue[liftEncoder] >= amount))
			wait1Msec(10); // let other tasks run
		driveSpeed(WHEELS_FORWARD * .1); // kill the momentum
	}
	
	wait1Msec(50);
	stopWheels();
}

void lockLift() {
	int x = SensorValue[liftEncoder]; // x value for quad
	int speed = -5 - 0.06143791*x - 0.0000307574*x*x;
	liftSpeed(speed);
}