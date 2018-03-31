#include "autonDefault.h"
#include "preAuton.h"

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
	//Leave this value alone
	int lcdScreenMin = 1;
	//This keeps track of which program you want to run
	int lcdScreen = 1;
	//Change this value to be the maximum number of programs you want on the robot
	int lcdScreenMax = 4;
	//Turns on the Backlight
	bLCDBacklight = true;

	//Copied from someone's sample code because the documentation for RobotC won't tell me anything useful
	//These should logically work, but I'm not 100% sure
	const short left = 1;
	const short center = 2;
	const short right = 4;

	selectedAuton = 1;
	bool autonConfirm = false;
	displayLCDString(0, 0, "Auton:");
	displayLCDNumber(1, 4, selectedAuton);
	while (!autonConfirm) {
		while (nLCDButtons == 0)
			/* wait for button to be pressed*/;

		switch (nLCDButtons) {
			case left:
			  selectedAuton--;
			  break;
			case center:
			  autonConfirm = true;
			  break;
			case right:
		    selectedAuton++;
			  break;
			case left + center:
			  break;
			case left + right:
			  break;
			case center + right:
			  break;
			case left + center + right:
			  break;
		}

		if (selectedAuton < 1)
			selectedAuton = 1;
	  else if (selectedAuton > nAutons)
	  	selectedAuton = nAutons;

		// TODO draw LCD stuff
	  clearLCDLine(1);
		displayLCDNumber(1, 4, selectedAuton);

		while (nLCDButtons != 0)
			/* wait for button to be released */;
	}
}
