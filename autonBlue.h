#ifndef _AUTON_BLUE_H_
#define _AUTON_BLUE_H_

void autonBlue();

// auton steps
void b_scorePreload();
void b_moveToBackBar();
void b_grabFirstMobileGoal();
void b_firstCorrectionTurn();
void b_grabSecondMobileGoal();
void b_scoreSecondCode();
void b_moveToBar();
void b_scoreMobileGoal();

#include "autonBlue.c"
#endif // _AUTON_BLUE_H_
