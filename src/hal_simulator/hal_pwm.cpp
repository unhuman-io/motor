

#include "hal_pwm.h"

#include "easylogging++.h"

namespace hal {
    void PWM::set_voltage(float a, float b, float c) {
        std::ostringstream s; s << "PWM::set_voltage, a:" << a << ", b:" << b << ", c:" << c;
        logging::INFO(s.str());
        v_abc_[0] = a;
        v_abc_[1] = b;
        v_abc_[2] = c;
    }
}