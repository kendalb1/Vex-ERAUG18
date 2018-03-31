#include "motion.h"
#include "sensors.h"

void autonDefault() {
	//Pre-Load score
  setPistons(PISTON_PUSH);
	wait1Msec(600);
	frictionDrumSpeed(DRUM_PULL);
	wait1Msec(200);
	frictionDrumSpeed(DRUM_HOLD);
	wait1Msec(2000);

	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}
