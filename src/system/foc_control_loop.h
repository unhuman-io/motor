

#ifndef MOTOR_FOCCONTROLLOOP_H
#define MOTOR_FOCCONTROLLOOP_H

#include "periodic_loop.h"
#include "periodic_communication.h"
#include "messages.h"

class FOC;

namespace hal {
    class PWM;
}

/// The high speed control loop
class FOCControlLoop : public PeriodicLoop, public PeriodicCommunication<FOCControlCommand, FOCControlParam, FOCControlStatus> {
public:
    FOCControlLoop(hal::PWM *pwm);
    virtual ~FOCControlLoop();
    virtual void update();
    virtual std::string name() { return "FOCControlLoop"; }

private:
    FOC *foc_;
    hal::PWM *pwm_;
};


#endif //MOTOR_FOCCONTROLLOOP_H
