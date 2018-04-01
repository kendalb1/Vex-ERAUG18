#ifndef _MOTION_PLUS_H_
#define _MOTION_PLUS_H_

typedef struct {
  float lastPosition;
  float lastTime;
  float velocity;
  float mass;
  int *motorPorts;
  int nPorts;
  int sensorPort;
} properties_t;
long motionPlusTimer = T4;

properties_t* buildProperties(properties_t *p, float currentPosition, float mass,
                              int *motorPorts, int nPorts, int sensorPort);
float momentum(properties_t p);
static void updateVelocity(properties_t *p);
task motionPlusUpdater();
void momentumMove(properties_t p, float target);

#include "motionPlus.c"
#endif // _MOTION_PLUS_H_
