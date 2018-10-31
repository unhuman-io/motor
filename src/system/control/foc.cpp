#include "foc.h"
#include "easylogging++.h"
#include "hal_fun.h"

#include "hal_pwm.h"

FOC::FOC(hal::PWM *pwm) : command_(), param_(), pwm_(pwm) {}

void FOC::set_command(const FOCCommand &command) {
    hal::atomic_memcpy(&command_, &command, sizeof(command_));
}

void FOC::step() {
    LOG(INFO) << "FOC::step()";
    static int i = 0;
    pwm_->set_voltage(command_.i_q, i++, 2);
}