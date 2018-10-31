#include "motor_simulator.h"

#include "easylogging++.h"


void MotorSimulator::set_current(float i_d, float i_q) {
    i_d_ = i_d;
    i_q_ = i_q;
}

void MotorSimulator::step() {
    velocity_ += i_q_ * 1;
    position_ += velocity_ * 1;
}

float MotorSimulator::get_position() const { return position_; }

float MotorSimulator::get_velocity() const { return velocity_; }