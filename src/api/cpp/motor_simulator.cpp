#include "motor_simulator.h"
#include "system.h"
#include "simulator.h"

namespace unhuman {
    MotorSimulator::MotorSimulator() {
        system_ = new System();
        simulator_ = new Simulator(*system_);
        simulator_->init(100);
    }

    MotorSimulator::~MotorSimulator() {
        delete simulator_;
        delete system_;
    }

    float MotorSimulator::get_message() {
        SimulatorStatus status;
        simulator_->get_status(&status);
        return status.motor_status.position;
    }
}