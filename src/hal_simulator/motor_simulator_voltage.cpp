#include "motor_simulator_voltage.h"
#include "hal_pwm.h"
#include "dq_transform.h"

#include "easylogging++.h"

void MotorSimulatorVoltage::step() {
    std::ostringstream s; s << pwm_->get_voltage()[0] << " " << pwm_->get_voltage()[1] << " " << pwm_->get_voltage()[2];
    logging::DEBUG(s.str());
    const float *v_dq = voltage_dq(pwm_->get_voltage());
}