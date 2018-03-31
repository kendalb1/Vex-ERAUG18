#include "userControl.h"

task lockMobile() {
	clearLCDLine(0);
	displayLCDNumber(0, 0, varU);
	if (varU == 0) {
		varU = 1;
		while (varU == 1) {
  		int dif = SensorValue[mobileEncoder] + 350;
  		motor[mobileCapture] = 127 * dif / 100;
  	}
	}
}
task usercontrol() {
	SensorValue[liftLeft] = 0;
	SensorValue[liftRight] = 0;
	while (true)
	{
		// Y component, X component, Rotation
	  int strafeVal = C1RX;
	  if (abs(strafeVal) < 20)
	  	strafeVal = 0;
		motor[frontLeft] = C1LY + C1LX + C1RX;
		motor[frontRight] =  -C1LY + C1LX + C1RX;
		motor[backRight] =  C1LY + C1LX - C1RX;
		motor[backLeft] = -C1LY + C1LX - C1RX;

		// Lift Controls
		if(vexRT [Btn5U] == 1) {
			motor[liftRight] = 127;
			motor[liftLeft] = 127;
		}
		else if(vexRT[Btn5D] == 1) {
			motor[liftRight] = -127;
			motor[liftLeft] = -127;
		}
		else {
			// max list val 850
			int idle = -3*SensorValue[liftEncoder]/85 - 5;
			clearLCDLine(0);
			displayLCDNumber(0, 0, SensorValue[liftEncoder]);
			clearLCDLine(1);
			displayLCDNumber(1, 0, idle);
			motor[liftLeft] = motor[liftRight] = idle;
		}
		
		static int drumIdle = 0;
		// Friction Drum Controls
		if(vexRT[Btn6U] == 1)
		{
			motor[frictionDrum2] = 127;
			drumIdle = 10;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[frictionDrum2] = -127;
			drumIdle = 0;
		}
		else
		{
			motor[frictionDrum2] = drumIdle;
		}
		//Pneumatics
		if (vexRT[Btn8D] == 1)
		{
			SensorValue[pistonOne]=0;
			SensorValue[pistonTwo]=0;
		}
		else if (vexRT[Btn8U] == 1)
		{
			SensorValue[pistonOne]=1;
			SensorValue[pistonTwo]=1;
		}

		//Mobile Goal control
		if (vexRT[Ch2] > 50) {
			motor[mobileCapture] = 127;
		}
		else if (vexRT[Ch2] < -50) {
			motor[mobileCapture] = -127;
		}
		else if (vexRT[Btn8L] == 1){
			startTask(lockMobile);
		}
		else {
			motor[mobileCapture] = 0;
		}
	}
}