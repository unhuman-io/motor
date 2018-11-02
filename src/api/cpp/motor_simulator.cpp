#include "motor_simulator.h"
#include "system.h"

namespace unhuman {
    MotorSimulator::MotorSimulator() {
        system_ = new System();
    }

    MotorSimulator::~MotorSimulator() {
        delete system_;
    }

    float MotorSimulator::get_message() {
        return system_->get_status().position;
    }
}