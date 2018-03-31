#include "motion.h"
#include "sensors.h"

void autonBlue() {
	b_scorePreload();

	b_moveToBackBar();

	b_grabFirstMobileGoal();

	b_firstCorrectionTurn();

	b_grabSecondMobileGoal();

	b_scoreSecondCode();

	b_moveToBar();

	b_scoreMobileGoal();
}
// ====== step definitions ======
void b_scorePreload() {
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

void b_moveToBackBar() {
	//first backward to the back bar
	driveRaw(-260);
	lockLift();
	stopWheels();
}

void b_grabFirstMobileGoal() {
	//first turn to line up with the mobile base
	while((SensorValue[rightEncoder] <= 665)) {
		turnSpeed(TURN_LEFT * .25);
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

void b_firstCorrectionTurn() {
	//second turn to correct
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[rightEncoder] >= 100)) {
	  turnSpeed(TURN_LEFT * .5);
	}
	stopWheels();
	wait1Msec(100);
	liftSpeed(0);
}

void b_grabSecondMobileGoal() {
	//third forward to grab the mobile goal
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[rightEncoder] >= -400)) {
		driveSpeed(WHEELS_FORWARD * .5);
	}
	stopWheels();
	wait1Msec(100);
}

void b_scoreSecondCode() {
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

void b_moveToBar() {
	//turn to align with the bar
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[rightEncoder] <= 1000)) {
		turnSpeed(TURN_LEFT * .5);
	}
	stopWheels();
	//motor[mobileCapture1] = 100;
	//motor[mobileCapture2] = 100;
	//wait1Msec(700);
	mobileCaptureSpeed(0);

	//fourth forward to get to the bar
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while((SensorValue[leftEncoder] <= 1500)) {
		driveSpeed(WHEELS_FORWARD * .5);
	}
	stopWheels();
}

void b_scoreMobileGoal() {
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
	wait1Msec(1000);
	stopWheels();
	wait1Msec(100);
	while(SensorValue[mobileEncoder] < 0){
		liftSpeed(LIFT_DOWN);
	}
	liftSpeed(0);
}
