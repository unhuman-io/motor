#include "motor_simulator_voltage.h"
#include "hal_pwm.h"
#include "dq_transform.h"

#include "easylogging++.h"

void MotorSimulatorVoltage::step() {
    LOG(INFO) << pwm_->get_voltage()[0] << " " << pwm_->get_voltage()[1] << " " << pwm_->get_voltage()[2];
    const float *v_dq = voltage_dq(pwm_->get_voltage());
    LOG(INFO) << v_dq[0] << " " << v_dq[1];
}