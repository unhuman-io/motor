
#ifndef MOTOR_SYSTEMUPDATELOOP_H
#define MOTOR_SYSTEMUPDATELOOP_H

#include "periodic_loop.h"

class SystemUpdateLoop : public PeriodicLoop {
public:
    virtual void init();
    virtual std::string name() { return "SystemUpdateLoop"; }
};


#endif //MOTOR_SYSTEMUPDATELOOP_H
