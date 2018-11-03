#ifndef MOTOR_MOTOR_SIMULATOR_H
#define MOTOR_MOTOR_SIMULATOR_H

#include "motor.h"

class System;
class Simulator;

namespace unhuman {
    class MotorSimulator : public Motor {
    public:
        virtual ~MotorSimulator();

        MotorSimulator();

        virtual float get_message();

    private:
        System *system_;
        Simulator *simulator_;
    };
}

#endif //MOTOR_MOTOR_SIMULATOR_H
