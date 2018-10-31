

#ifndef MOTOR_FOCCONTROLLOOP_H
#define MOTOR_FOCCONTROLLOOP_H

#include "periodic_loop.h"

class FOC;

namespace hal {
    class PWM;
}

/// The high speed control loop
class FOCControlLoop : public PeriodicLoop {
public:
    FOCControlLoop(hal::PWM *pwm);
    virtual ~FOCControlLoop();
    virtual void step();

private:
    FOC *foc_;
    hal::PWM *pwm_;
};


#endif //MOTOR_FOCCONTROLLOOP_H
