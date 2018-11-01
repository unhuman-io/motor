#ifndef MOTOR_MOTOR_SIMULATOR_H
#define MOTOR_MOTOR_SIMULATOR_H

#include "motor.h"

class System;

class MotorSimulator1 : public Motor {
public:
    virtual ~MotorSimulator1();
    MotorSimulator1();
    virtual float get_message();
private:
    System *system_;
};


#endif //MOTOR_MOTOR_SIMULATOR_H
