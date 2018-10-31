

#include "hal_pwm.h"

#include "easylogging++.h"

namespace hal {
    void PWM::set_voltage(float a, float b, float c) {
        LOG(INFO) << "PWM::set_voltage, a:" << a << ", b:" << b << ", c:" << c;
        v_abc_[0] = a;
        v_abc_[1] = b;
        v_abc_[2] = c;
    }
}