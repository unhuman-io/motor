
#include "simulator/system.h"
#include "easylogging++.h"
#include <chrono>
#include <thread>

//INITIALIZE_EASYLOGGINGPP

int main() {
//    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

    System *system = new System;

//    // No FOC simulation
//    for(int i=0; i<10; i++) {
//        main_control_loop.step();
//        motor.set_current(1, 2);
//        motor.step();
//        motor_status.position = motor.get_position();
//        motor_status.velocity = motor.get_velocity();
//        LOG(INFO) << "motor position: " << motor.get_position();
//        LOG(INFO) << "motor_velocity: " << motor.get_velocity();
//    }
//
//    // With FOC simulation
//    for(int i=0; i<10; i++) {
//        foc_control_loop.step();
//        motor_sim_voltage.step();
//    }

    std::this_thread::sleep_for(std::chrono::seconds(1000));

    delete system;

    return 0;
}