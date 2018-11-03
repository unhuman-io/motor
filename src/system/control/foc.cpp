#include "foc.h"
#include "easylogging++.h"
#include "hal_fun.h"
#include "hal_adc.h"

#include "hal_pwm.h"

FOC::FOC(hal::PWM *pwm, const hal::ADC &adc) : pwm_(pwm), adc_(adc) {}

void FOC::update() {
    static int i = 0;
    update_command();
    status_.desired.i_d = command_.i_d;
    status_.desired.i_q = command_.i_q;
    adc_.get_adc();
    pwm_->set_voltage(command_.i_q, i++, 2);
    update_status();
}