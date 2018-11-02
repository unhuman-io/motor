
#ifndef MOTOR_SYSTEMUPDATELOOP_H
#define MOTOR_SYSTEMUPDATELOOP_H

#include "periodic_loop.h"
#include "periodic_communication.h"
#include "messages.h"

class SystemUpdateLoop : public PeriodicLoop, public PeriodicCommunication<SystemUpdateCommand, SystemUpdateParam, SystemUpdateStatus> {
public:
    virtual void init();
    virtual std::string name() { return "SystemUpdateLoop"; }
};


#endif //MOTOR_SYSTEMUPDATELOOP_H
