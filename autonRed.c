#include "motion.h"
#include "sensors.h"

void autonRed() {
	r_scorePreload();

	r_moveToBackBar();

	r_grabFirstMobileGoal();

	r_firstCorrectionTurn();

	r_grabSecondMobileGoal();

	r_scoreSecondCode();

	r_moveToBar();

	r_scoreMobileGoal();
}
// ====== step definitions ======
void r_scorePreload() {
	while((SensorValue[mobileEncoder] >= -720)) {
		liftSpeed(LIFT_UP);
	}
	lockLift();
	wait1Msec(100);
	frictionDrumSpeed(DRUM_HOLD);

	//first forward to score preload
	driveRaw(450);
	wait1Msec(100);

	//Pre-Load score
	setPistons(PISTON_PUSH);
	wait1Msec(600);
	frictionDrumSpeed(DRUM_PULL);
	wait1Msec(200);
	frictionDrumSpeed(0);
	wait1Msec(2000);
}

void r_moveToBackBar() {
	//first backward to the back bar
	driveRaw(-280);
	lockLift();
	stopWheels();
}

void r_grabFirstMobileGoal() {
	//first turn to line up with the mobile base
	while((SensorValue[rightEncoder] >= 115)) {
		turnSpeed(TURN_RIGHT * .25);
	}
	stopWheels();
	wait1Msec(100);

	//extend mobile capture
	while(SensorValue[liftEncoder] > -575) {
		mobileCaptureSpeed(CAPTURE_EXTEND * .8);
	}

	mobileCaptureSpeed(0);
	wait1Msec(100);


	//second forward to grab the mobile goal
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[leftEncoder] < 1000)) {
		driveSpeed(WHEELS_FORWARD * .5);
	}
	stopWheels();
	wait1Msec(100);
	liftSpeed(0);
	wait1Msec(600);
}

void r_firstCorrectionTurn() {
	//second turn to correct
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	wait1Msec(100);
	while((SensorValue[rightEncoder] <= -100)) {
		turnSpeed(TURN_LEFT * .5);
	}
	stopWheels();
	wait1Msec(100);
	liftSpeed(0);
}

void r_grabSecondMobileGoal() {
	//third forward to grab the mobile goal
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[rightEncoder] >= -400)) {
		driveSpeed(WHEELS_FORWARD * .5);
	}
	stopWheels();
	wait1Msec(100);
}

void r_scoreSecondCode() {
	//third forward to score the second cone
	while((SensorValue[leftEncoder] <= 400)) {
		driveSpeed(WHEELS_FORWARD * .5);
	}
	//retract mobile capture
	while(SensorValue[liftEncoder] < -300) {
		mobileCaptureSpeed(CAPTURE_RETRACT * .8);
	}
	mobileCaptureSpeed(CAPTURE_EXTEND * .1);
	stopWheels();
	wait1Msec(100);
}

void r_moveToBar() {
	//turn to align with the bar
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[leftEncoder] <= 1000)) {
		turnSpeed(TURN_LEFT * .5);
	}
	stopWheels();
	//motor[mobileCapture1] = 100;
	//motor[mobileCapture2] = 100;
	//wait1Msec(700);
	mobileCaptureSpeed(0);

	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	//fourth forward to get to the bar
	driveRaw(1500);
}

void r_scoreMobileGoal() {
	//back up to score
	driveRaw(-185);
	//extend the mobile capture
	while(SensorValue[liftEncoder] > -600) {
		mobileCaptureSpeed(CAPTURE_EXTEND * .8);
	}
	mobileCaptureSpeed(0);
	wait1Msec(100);
	stopWheels();
	wait1Msec(100);
	driveSpeed(WHEELS_FORWARD);
	wait1Msec(400);
	stopWheels();
	wait1Msec(100);
}
