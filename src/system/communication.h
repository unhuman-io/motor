

#ifndef MOTOR_COMMUNICATION_H
#define MOTOR_COMMUNICATION_H

#include "messages.h"


class Communication {
public:
    Communication() : command_in_(), command_() {}
    /// Stores one command only for use by the high speed loop. It will provide a reference
    /// that will not change until the next get_command().
    MotorCommand& get_command();

    /// A message is input to this object. Generally will likely come from interrupt instead.
    void send_message(Message *m);

private:
    MotorCommand command_in_, command_;

};


#endif //MOTOR_COMMUNICATION_H
