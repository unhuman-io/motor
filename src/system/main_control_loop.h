
#ifndef MOTOR_MAINCONTROLLOOP_H
#define MOTOR_MAINCONTROLLOOP_H

#include "periodic_loop.h"


class MainControlLoop : public PeriodicLoop {
public:
    virtual void step();
    virtual std::string name() { return "MainControlLoop"; }
};


#endif //MOTOR_MAINCONTROLLOOP_H
