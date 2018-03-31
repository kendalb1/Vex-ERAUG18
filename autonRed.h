#ifndef _AUTON_RED_H_
#define _AUTON_RED_H_

void autonRed();

// auton steps
void r_scorePreload();
void r_moveToBackBar();
void r_grabFirstMobileGoal();
void r_firstCorrectionTurn();
void r_grabSecondMobileGoal();
void r_scoreSecondCode();
void r_moveToBar();
void r_scoreMobileGoal();

#include "autonRed.c"
#endif // _AUTON_RED_H_
