#include "system.h"

#include "system_update_loop.h"
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

#include "hal_fun.h"
#include "hal_pwm.h"

#include "messages.h"
#include "easylogging++.h"

System::System() {
//    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    //todo pwm goes away
    hal::PWM pwm;
    //   MotorSimulator motor;
    //   MotorSimulatorVoltage motor_sim_voltage(&pwm);

    system_update_loop_ = new SystemUpdateLoop;
    main_control_loop_ = new MainControlLoop;
    foc_control_loop_ = new FOCControlLoop(&pwm);
//    communication_ = new Communication;
//    //MotorStatus motor_status;
//
    system_update_loop_->init();
    main_control_loop_->init(10);
    foc_control_loop_->init(100);
}

System::~System() {
    delete system_update_loop_;
    delete main_control_loop_;
    delete foc_control_loop_;
    logging::WARN("~System()");
}