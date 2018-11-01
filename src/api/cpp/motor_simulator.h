#ifndef MOTOR_MOTOR_SIMULATOR_H
#define MOTOR_MOTOR_SIMULATOR_H

#include "motor.h"

class System;

class MotorSimulator : public Motor {
public:
    virtual ~MotorSimulator();
    MotorSimulator();
private:
    System *system_;
};


#endif //MOTOR_MOTOR_SIMULATOR_H
