#ifndef MOTOR_FOC_H
#define MOTOR_FOC_H

#include "messages.h"

namespace hal {
    class PWM;
}

class FOC {
public:
    FOC(hal::PWM *pwm);
    //TODO:  maybe template these functions
    void set_param(const FOCParam &param) { param_ = param; }
    void get_param(FOCParam *param) const { *param = param_;}
    void set_command(const FOCCommand &);
    void step();

private:
    FOCParam param_;
    FOCCommand command_;
    hal::PWM *pwm_;
};


#endif //MOTOR_FOC_H
