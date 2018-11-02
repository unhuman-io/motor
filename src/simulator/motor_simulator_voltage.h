#ifndef MOTOR_MOTOR_SIMULATOR_VOLTAGE_H
#define MOTOR_MOTOR_SIMULATOR_VOLTAGE_H

#include "motor_simulator.h"

namespace hal {
    class PWM;
}

class MotorSimulatorVoltage : public MotorSimulator {
public:
    MotorSimulatorVoltage(System &system, hal::PWM *pwm) : MotorSimulator(system), pwm_(pwm) {}
    virtual void update();
private:
    hal::PWM *pwm_;
};


#endif //MOTOR_MOTOR_SIMULATOR_VOLTAGE_H
