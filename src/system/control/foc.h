#ifndef MOTOR_FOC_H
#define MOTOR_FOC_H

#include <periodic_communication.h>
#include "messages.h"

namespace hal {
    class PWM;
}

class FOC : public PeriodicCommunication<FOCCommand, FOCParam, FOCStatus> {
public:
    FOC(hal::PWM *pwm);
    //TODO:  maybe template these functions
    void update();

private:
    hal::PWM *pwm_;
};


#endif //MOTOR_FOC_H
