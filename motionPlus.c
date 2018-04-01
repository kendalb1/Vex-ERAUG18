
properties_t* buildProperties(properties_t *p, float currentPosition, float mass,
                              int *motorPorts, int nPorts, int sensorPort) {
  p->lastPosition = currentPosition;
  p->lastTime     = 0;
  p->mass         = mass;
  p->motorPorts   = motorPorts;
  p->nPorts       = nPorts;
  p->sensorPort   = sensorPort;

  return p;
}

float momentum(properties_t p) {
  return p.velocity * p.mass;
}

static void updateVelocity(properties_t *p) {
  const float currentPosition = SensorValue[p->sensorPort];
  const float currentTime     = time1(motionPlusTimer);

  // update the velocity
  p->velocity = (currentPosition - p->lastPosition)/(currentTime - p->lastTime);

  // current values are now previous values
  p->lastPosition = currentPosition;
  p->lastTime = currentTime;
}

static void setupProperties(properties_t *leftDrive, properties_t *rightDrive,
                            properties_t *lift, properties_t *capture) {
//#error "pos_unfinished"
	int leftDrivePos      = -1,
	    rightDrivePos     = -1,
	    liftPos           = -1,
	    capturePos        = -1;

//#error "mass_unfinished"
	int leftDriveMass     = -1,
	    rightDriveMass    = -1,
	    liftMass          = -1,
	    captureMass       = -1;

//#error "ports_unfinished"
	int leftDrivePorts[]  = {0},
	    rightDrivePorts[] = {0},
	    liftPorts[]       = {0},
	    capturePorts[]    = {0};

//#error "nports_unfinished"
	int leftDriveNPorts   = -1,
	    rightDriveNPorts  = -1,
	    liftNPorts        = -1,
	    captureNPorts     = -1;

//#error "sensor_unfinished"
	int leftDriveSensor   = -1,
	    rightDriveSensor  = -1,
	    liftSensor        = -1,
	    captureSensor     = -1;

  buildProperties(leftDrive,   leftDrivePos,  leftDriveMass,  leftDrivePorts,  leftDriveNPorts,  leftDriveSensor);
  buildProperties(rightDrive,  rightDrivePos, rightDriveMass, rightDrivePorts, rightDriveNPorts, rightDriveSensor);
  buildProperties(lift,        liftPos,       liftMass,       liftPorts,       liftNPorts,       liftSensor);
  buildProperties(capture,     capturePos,    captureMass,    capturePorts,    captureNPorts,    captureSensor);
}
task motionPlusUpdater() {
  properties_t *leftDrive, *rightDrive, *lift, *capture;
  setupProperties(leftDrive, rightDrive, lift, capture);

  ClearTimer(motionPlusTimer); // clear timer after building all properties
  while (true) {
    // update velocities
    updateVelocity(leftDrive);
    updateVelocity(rightDrive);
    updateVelocity(lift);
    updateVelocity(capture);

    // let other tasks work
    wait1Msec(10);
  }
}
