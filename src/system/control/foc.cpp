#include "foc.h"
//#include "easylogging++.h"
#include "hal_fun.h"
#include "hal_adc.h"

#include "hal_pwm.h"
#include "../sensor/encoder.h"
#include "control_fun.h"

#include <cmath>

FOC::FOC(hal::PWM *pwm, const hal::ADC &adc, const Encoder &encoder) : pwm_(pwm), adc_(adc), encoder_(encoder) {
    pi_id_ = new PIController();
    pi_iq_ = new PIController();
}

FOC::~FOC() {
    delete pi_id_;
    delete pi_iq_;
}

#define SQRT3 (float) std::sqrt(3)
static const float Kc[2][3] = {2.0/3 -1.0/3 -1.0/3,
                               0,      1/SQRT3, -1/SQRT3};

void FOC::update() {
    static int i = 0;
    update_command();
    status_.measured.position = encoder_.get_position();
    status_.desired.i_d = command_.i_d;
    status_.desired.i_q = command_.i_q;
    adc_.get_adc();
    float i_abc_measured[3] = {};
    float electrical_angle = status_.measured.position * num_poles_;

    float sin_t = std::sin(electrical_angle);
    float cos_t = std::cos(electrical_angle);

    float  i_alpha_measured = Kc[0][0] * i_abc_measured[0] +
            Kc[0][1] * i_abc_measured[1] +
            Kc[0][2] * i_abc_measured[2];
    float  i_beta_measured = Kc[1][0] * i_abc_measured[0] +
                     Kc[1][1] * i_abc_measured[1] +
                     Kc[1][2] * i_abc_measured[2];

    float i_d_measured = cos_t * i_alpha_measured - sin_t * i_beta_measured;
    float i_q_measured = sin_t * i_alpha_measured + cos_t * i_beta_measured;

    float v_d_desired = pi_id_->step(status_.desired.i_d, i_d_measured);
    float v_q_desired = pi_iq_->step(status_.desired.i_q, i_q_measured);

    float v_alpha_desired = cos_t * v_d_desired + sin_t * v_q_desired;
    float v_beta_desired = -sin_t * v_d_desired + cos_t * v_q_desired;

    float v_a_desired = Kc[0][0] * v_alpha_desired + Kc[1][0] * v_beta_desired;
    float v_b_desired = Kc[0][1] * v_alpha_desired + Kc[1][1] * v_beta_desired;
    float v_c_desired = Kc[0][2] * v_alpha_desired + Kc[1][2] * v_beta_desired;

    pwm_->set_voltage(v_a_desired, v_b_desired, v_c_desired);
    update_status();
}