#include "motor_simulator.h"

#include "easylogging++.h"
#include "system.h"

void MotorSimulator::init(int32_t frequency_hz) {
    PeriodicLoop::init(frequency_hz);
}

void MotorSimulator::set_current(float i_d, float i_q) {
    i_d_ = i_d;
    i_q_ = i_q;
}

void MotorSimulator::update() {
    MotorStatus status;
    status = system_.get_status();

    // calculate current, position
    velocity_ += i_q_ * 1;
    position_ += velocity_ * 1;

    // update sensors
   // adc_.adc_result_[0] = 2048;
}

float MotorSimulator::get_position() const { return position_; }

float MotorSimulator::get_velocity() const { return velocity_; }