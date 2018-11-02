#ifndef MOTOR_SYSTEM_H
#define MOTOR_SYSTEM_H

#include "messages.h"

class SystemUpdateLoop;
class MainControlLoop;
class FOCControlLoop;
class Communication;

namespace hal {
    class PWM;
}

class System {
public:
    System();
    ~System();
    MotorStatus get_status();
private:
    SystemUpdateLoop *system_update_loop_;
    MainControlLoop *main_control_loop_;
    FOCControlLoop *foc_control_loop_;
    Communication *communication_;
    hal::PWM *pwm_;
    MotorStatus motor_status_;
};

#endif //MOTOR_SYSTEM_H
