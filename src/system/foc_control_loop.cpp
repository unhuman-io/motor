

#include "foc_control_loop.h"
#include "control/foc.h"

FOCControlLoop::FOCControlLoop(hal::PWM *pwm, const hal::ADC &adc) : PeriodicCommunication(), pwm_(pwm) {
    foc_ = new FOC(pwm_, adc);
    FOCParam foc_param = {};
    foc_->set_param(foc_param);
}

FOCControlLoop::~FOCControlLoop() {
    delete foc_;
}

void FOCControlLoop::update() {
    PeriodicLoop::update();
    foc_->set_command(command_.command);
    foc_->update();
}