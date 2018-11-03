#include "brushless_motor_simulation.h"

void BrushlessMotorSimulation::update() {
    // calculate current, position
    status_.velocity += command_.v_abc[0];
    status_.position += status_.velocity * 1;
}