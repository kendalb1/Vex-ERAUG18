#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in3,    gyroSens,       sensorGyro)
#pragma config(Sensor, dgtl2,  pistonTwo,      sensorDigitalOut)
#pragma config(Sensor, dgtl3,  pistonOne,      sensorDigitalOut)
#pragma config(Sensor, I2C_1,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  mobileEncoder,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  liftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           liftRight,     tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port3,           mobileCapture, tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port6,           backRight,     tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port8,           frictionDrum2, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           liftLeft,      tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_4)

#include "motion.h"
#include "sensors.h"

void stall();
void info(string s);
void testAllMotors();
void testAllSensors();

task main() {
	// test code here
}

void stall() {
	while ((int)nLCDButtons == 0)
		/* stall for button to be pressed */;
	while ((int)nLCDButtons != 0)
		/* stall for button to be released */;
}

void info(string s) {
	stopAllMotors();
	clearLCDLine(0);
	displayLCDString(0, 0, s);
	stall();
}

void testAllMotors() {
	info("PISTONS");
	setPistons(PISTON_PUSH);
	stall();
	setPistons(PISTON_PULL);
	stall();
	
	info("DRUMS");
	frictionDrumSpeed(DRUM_PULL);
	stall();
	frictionDrumSpeed(DRUM_PUSH);
	stall();
	frictionDrumSpeed(DRUM_HOLD);
	stall();
	
	info( "LIFT");
	liftSpeed(LIFT_UP);
	stall();
	liftSpeed(LIFT_DOWN);
	stall();
	
	info("DRIVE F/B");
	driveSpeed(WHEELS_FORWARD);
	stall();
	driveSpeed(WHEELS_BACKWARD);
	stall();
	
	info("TURN");
	turnSpeed(TURN_RIGHT);
	stall();
	turnSpeed(TURN_LEFT);
	stall();
	
	info("CAPTURE");
	mobileCaptureSpeed(CAPTURE_EXTEND);
	stall();
	mobileCaptureSpeed(CAPTURE_RETRACT);
	stall();
}

void testAllSensors() {
	info("DRIVE INCHES");
	driveIn(float inches);
	
	info("DRIVE RAW");
	driveRaw(int amount);
	
	info("ROTATE DEG");
	rotateDeg(float degrees);
	
	info("ROTATE RAW");
	rotateRaw(int amount);
	
	info("LIFT POS");
	setLiftPos(int position);
	
	info("LIFT LOCK");
	lockLift();
	
	info("MOBILE POS");
	setMobileCapturePos(int position);
}