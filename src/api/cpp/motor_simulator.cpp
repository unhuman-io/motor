#include "motor_simulator.h"
#include "system.h"

MotorSimulator1::MotorSimulator1() {
    system_ = new System();
}

MotorSimulator1::~MotorSimulator1() {
    delete system_;
}

float MotorSimulator1::get_message() {
    return system_->get_status().position;
}