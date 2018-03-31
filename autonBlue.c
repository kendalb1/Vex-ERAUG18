
void autonBlue() {
	//if(Program == 1){
	SensorValue[pistonOne] = 0;
	SensorValue[pistonTwo] = 0;
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	SensorValue[I2C_3] = 0;
	while((SensorValue[I2C_3] >= -720))
	{
		motor[liftLeft] = 125;
		motor[liftRight] = 125;
	}
	motor[liftLeft] = 80;
	motor[liftRight] = 80;
	wait1Msec(100);
	motor[frictionDrum2] = 10;

	//first forward to score preload
	while((SensorValue[I2C_1] <= 450))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

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

	//first backward to the back bar
	while((SensorValue[I2C_1] >= -260))
	{
		motor[frontLeft] = -60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = 60;
	}
	motor[liftLeft] = 80;
	motor[liftRight] = 80;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;



	//first turn to line up with the mobile base
	while((SensorValue[I2C_2] <= 665))
	{
		motor[frontLeft] = 30;
		motor[frontRight] = 30;
		motor[backRight] = -30;
		motor[backLeft] = -30;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	//extend mobile capture
	while(SensorValue[I2C_4] > -700){
		motor[mobileCapture] = 50;
	}

	motor[mobileCapture] = 0;
	wait1Msec(100);
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;


	//second forward to grab the mobile goal
	while((SensorValue[I2C_1] < 1000))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
	wait1Msec(600);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	wait1Msec(100);

	//second turn to correct
	//while((SensorValue[I2C_2] >= 100))
	//{
	//	motor[frontLeft] = -60;
	//	motor[frontRight] = -60;
	//	motor[backRight] = 60;
	//	motor[backLeft] = 60;
	//}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

	motor[liftLeft] = 0;
	motor[liftRight] = 0;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	////thirdnforward tio grab the mobile goal
	//	while((SensorValue[I2C_2] >= -400)) {
	//		motor[frontLeft] 	= 60;
	//		motor[frontRight] = -60;
	//		motor[backLeft]		= -60;
	//		motor[backRight]	= 60;
	//	}

	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	//third forward to score the second cone
	while((SensorValue[I2C_1] <= 400))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	//retract mobile capture
	while(SensorValue[I2C_4] < -300){
		motor[mobileCapture] = -100;
	}
	motor[mobileCapture] = 10;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	//turn to align with the bar
	while((SensorValue[I2C_2] <= 1000))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	//motor[mobileCapture1] = 100;
	//motor[mobileCapture2] = 100;
	//wait1Msec(700);
	motor[mobileCapture] = 0;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	//fourth forward to get to the bar
	while((SensorValue[I2C_1] <= 1500))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;

	//back up to score
	while((SensorValue[I2C_1] <= 185))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = -60;
	}
	//extend the mobile capture
	while(SensorValue[I2C_4] > -600){
		motor[mobileCapture] = 100;
	}
	motor[mobileCapture] = 0;
	wait1Msec(100);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	motor[frontLeft] = -125;
	motor[frontRight] = 125;
	motor[backRight] = 125;
	motor[backLeft] = -125;
	wait1Msec(1000);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	while(SensorValue[I2C_3] < 0){
		motor[liftLeft] = -127;
		motor[liftRight] = -127;
	}
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
}