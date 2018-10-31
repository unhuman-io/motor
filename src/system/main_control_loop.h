
#ifndef MOTOR_MAINCONTROLLOOP_H
#define MOTOR_MAINCONTROLLOOP_H

#include "periodic_loop.h"


class MainControlLoop : public PeriodicLoop {
public:
    virtual void step();
};


#endif //MOTOR_MAINCONTROLLOOP_H
