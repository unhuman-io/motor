#include "foc.h"
#include "easylogging++.h"
#include "hal_fun.h"

#include "hal_pwm.h"

FOC::FOC(hal::PWM *pwm) : pwm_(pwm) {}

void FOC::update() {
    static int i = 0;
    status_.desired.i_d = command_.i_d;
    status_.desired.i_q = command_.i_q;
    pwm_->set_voltage(command_.i_q, i++, 2);
}