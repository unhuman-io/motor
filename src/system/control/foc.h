#ifndef MOTOR_FOC_H
#define MOTOR_FOC_H

#include <periodic_communication.h>
#include "messages.h"

namespace hal {
    class PWM;
    class ADC;
}

class FOC : public PeriodicCommunication<FOCCommand, FOCParam, FOCStatus> {
public:
    FOC(hal::PWM *pwm, const hal::ADC &adc);
    //TODO:  maybe template these functions
    void update();

private:
    hal::PWM *pwm_;
    const hal::ADC &adc_;
};


#endif //MOTOR_FOC_H
