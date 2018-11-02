#ifndef MOTOR_MOTOR_SIMULATOR_H
#define MOTOR_MOTOR_SIMULATOR_H

#include "motor.h"

class System;

namespace unhuman {
    class MotorSimulator : public Motor {
    public:
        virtual ~MotorSimulator();

        MotorSimulator();

        virtual float get_message();

    private:
        System *system_;
    };
}

#endif //MOTOR_MOTOR_SIMULATOR_H
