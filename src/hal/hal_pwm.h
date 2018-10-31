#ifndef MOTOR_HAL_PWM_H
#define MOTOR_HAL_PWM_H

namespace hal {
    class PWM {
    public:
        void set_voltage(float a, float b, float c);
        const float *get_voltage() const { return v_abc_; }
    private:
        float v_abc_[3];
    };
}
#endif //MOTOR_HAL_PWM_H
