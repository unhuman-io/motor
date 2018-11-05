#ifndef MOTOR_HAL_MOTOR_H
#define MOTOR_HAL_MOTOR_H

#include "periodic_loop.h"
#include "periodic_communication.h"
#include "messages.h"

class System;
class MotorSimulation;

class Simulator
        : public PeriodicLoop,
          public PeriodicCommunication<SimulatorCommand, SimulatorParam, SimulatorStatus> {
public:
    Simulator(System &system);
    ~Simulator();

    void init(int32_t frequency_hz);


    virtual void update();

    float get_position() const;

    float get_velocity() const;

    void send_message(Message *m);

private:
    float position_, velocity_;
    System &system_;
    MotorSimulation *motor_simulation_;

};



#endif //MOTOR_HAL_MOTOR_H
