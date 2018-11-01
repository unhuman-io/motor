#include "system.h"

#include "system_update_loop.h"
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

#include "hal_fun.h"
#include "hal_pwm.h"
#include "motor_simulator.h"

#include "messages.h"
#include "easylogging++.h"

System::System() : motor_status_() {
//    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    pwm_ = new hal::PWM;

    //   MotorSimulatorVoltage motor_sim_voltage(&pwm);

    system_update_loop_ = new SystemUpdateLoop;
    main_control_loop_ = new MainControlLoop;
    foc_control_loop_ = new FOCControlLoop(pwm_);
    motor_simulator_ = new MotorSimulator();
//    communication_ = new Communication;
//    //MotorStatus motor_status;
//
    system_update_loop_->init();
    main_control_loop_->init(10);
    foc_control_loop_->init(100);
    motor_simulator_->init(100);

    motor_simulator_->set_current(1,2);
}

System::~System() {
    logging::WARN("~System()");
    delete system_update_loop_;
    delete main_control_loop_;
    delete foc_control_loop_;
    delete motor_simulator_;
    delete pwm_;
    logging::WARN("Done ~System()");
}

MotorStatus System::get_status() {
    motor_status_.position = motor_simulator_->get_position();
    motor_status_.velocity = motor_simulator_->get_velocity();
    return motor_status_;
}