

#ifndef MOTOR_FOCCONTROLLOOP_H
#define MOTOR_FOCCONTROLLOOP_H

#include "periodic_loop.h"

class FOC;

/// The high speed control loop
class FOCControlLoop : public PeriodicLoop {
public:
    FOCControlLoop();
    virtual ~FOCControlLoop();
    virtual void step();

private:
    FOC *foc_;
};


#endif //MOTOR_FOCCONTROLLOOP_H
