#ifndef MOTOR_MOTOR_H
#define MOTOR_MOTOR_H

#include "messages.h"

class Motor {
public:
    void send_message(Message *m) {}
    float get_message() { return 1.1; }

};


#endif //MOTOR_MOTOR_H
