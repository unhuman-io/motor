

#include "foc_control_loop.h"
#include "control/foc.h"

FOCControlLoop::FOCControlLoop(hal::PWM *pwm) : pwm_(pwm) {
    foc_ = new FOC(pwm_);
    FOCParam foc_param = {};
    foc_->set_param(foc_param);
}

FOCControlLoop::~FOCControlLoop() {
    delete foc_;
}

void FOCControlLoop::step() {
    PeriodicLoop::step();
    FOCCommand foc_command = {};
    foc_->set_command(foc_command);
    foc_->step();
}