#include "motor_simulator.h"
#include "system.h"

MotorSimulator::MotorSimulator() {
    system_ = new System();
}

MotorSimulator::~MotorSimulator() {
    delete system_;
}