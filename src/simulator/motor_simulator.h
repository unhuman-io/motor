#ifndef MOTOR_HAL_MOTOR_H
#define MOTOR_HAL_MOTOR_H

#include "periodic_loop.h"
#include "periodic_communication.h"
#include "messages.h"

class System;

class MotorSimulator : public PeriodicLoop, public PeriodicCommunication<MotorSimulatorCommand, MotorSimulatorParam, MotorSimulatorStatus> {
public:
    MotorSimulator(System &system) : system_(system), position_(), velocity_(), i_d_(), i_q_() {}
    void init(int32_t frequency_hz);
    void set_current(float i_d, float i_q);
    virtual void update();
    float get_position() const;
    float get_velocity() const;
private:
    float i_d_, i_q_;
    float position_, velocity_;
    System &system_;
};


#endif //MOTOR_HAL_MOTOR_H
