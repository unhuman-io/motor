#include "system.h"

#include "system_update_loop.h"
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

#include "hal_fun.h"
#include "hal_pwm.h"
#include "hal_adc.h"
#include "sensor/encoder.h"

#include "messages.h"
#include "easylogging++.h"

System::System() : motor_status_() {
    pwm_ = new hal::PWM;
    adc_ = new hal::ADC;
    motor_encoder_ = new Encoder;
    system_update_loop_ = new SystemUpdateLoop;
    main_control_loop_ = new MainControlLoop;
    foc_control_loop_ = new FOCControlLoop(pwm_, *adc_, *motor_encoder_);
    communication_ = new Communication;

    system_update_loop_->init();
    main_control_loop_->init(10, *foc_control_loop_, *communication_);
    foc_control_loop_->init(100);
}

System::~System() {
    logging::WARN("~System()");
    delete system_update_loop_;
    delete main_control_loop_;
    delete foc_control_loop_;
    delete communication_;
    delete pwm_;
    delete motor_encoder_;
    logging::WARN("Done ~System()");
}

MotorStatus System::get_status() {
    MainControlStatus status;
    main_control_loop_->get_status(&status);
    motor_status_ = status.motor_status;
    return motor_status_;
}