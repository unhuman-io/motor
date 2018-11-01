#ifndef MOTOR_MOTOR_H
#define MOTOR_MOTOR_H

#include "messages.h"

class Motor {
public:
    virtual ~Motor();
    virtual void send_message(Message *m) {}
    virtual float get_message() { return 1.1; }

};


#endif //MOTOR_MOTOR_H
