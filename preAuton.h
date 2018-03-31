#ifndef _PRE_AUTON_H_
#define _PRE_AUTON_H_

int selectedAuton;

// pre_auton() is already defined in the competition includes
void selectAuton();
void resetSensors();
void resetGyro();

#include "preAuton.c"
#endif // _PRE_AUTON_H_
