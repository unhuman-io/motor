
#ifndef MOTOR_MAINCONTROLLOOP_H
#define MOTOR_MAINCONTROLLOOP_H

#include "periodic_loop.h"
#include "periodic_communication.h"
#include "messages.h"

class FOCControlLoop;
class Communication;

class MainControlLoop : public PeriodicLoop, public PeriodicCommunication<MainControlCommand, MainControlParam, MainControlStatus> {
public:
    virtual void update();
    virtual std::string name() { return "MainControlLoop"; }
    void init(int32_t frequency_hz, FOCControlLoop &, Communication &);
private:
    FOCControlLoop *foc_control_loop_;
    Communication *communication_;
};


#endif //MOTOR_MAINCONTROLLOOP_H
