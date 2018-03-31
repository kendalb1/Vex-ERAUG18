#ifndef _USER_CONTROL_H_
#define _USER_CONTROL_H_

#define C1LX vexRT[Ch4]
#define C1LY vexRT[Ch3]
#define C1RX vexRT[Ch1]

bool mobileCaptureIsLocked; // control variable for task lockMobile();

// usercontrol is already defined in the competition includes
task lockMobile();

#include "userControl.c"
#endif // _USER_CONTROL_H_
