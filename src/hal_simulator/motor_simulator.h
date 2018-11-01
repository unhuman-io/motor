#ifndef MOTOR_HAL_MOTOR_H
#define MOTOR_HAL_MOTOR_H

#include "periodic_loop.h"

class MotorSimulator : public PeriodicLoop {
public:
    MotorSimulator() : position_(), velocity_(), i_d_(), i_q_() {}
    void set_current(float i_d, float i_q);
    virtual void step();
    float get_position() const;
    float get_velocity() const;
private:
    float i_d_, i_q_;
    float position_, velocity_;
};


#endif //MOTOR_HAL_MOTOR_H
