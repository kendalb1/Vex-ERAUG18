
void autonDefault() {
	//Pre-Load score
	SensorValue[pistonOne] = 1;
	SensorValue[pistonTwo] = 1;
	wait1Msec(100);
	wait1Msec(500);
	motor[frictionDrum2] = -127;
	wait1Msec(200);
	motor[frictionDrum2] = 0;
	wait1Msec(2000);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
}