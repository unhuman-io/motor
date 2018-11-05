#include "motor_simulation.h"


void MotorSimulation::update() {
    // calculate position
    float torque = kt_ * command_.i;
    float acceleration = torque/Im_;

    status_.velocity += acceleration * dt_;
    status_.position += status_.velocity * dt_;
}