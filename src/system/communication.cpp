

#include "communication.h"
#include <cstring>
#include <messages.h>
#include <sstream>
#include "logging.h"

MotorCommand &Communication::get_command() {
    command_ = command_in_;
    return command_;
}

void Communication::send_message(Message *m) {
    std::ostringstream s;
    s << "Got Message, type: " << m->type << " data: ";
    for(int i=0; i<10; i++) {
       s << std::hex << +(m->data[i]);
       s << " ";
    }
   // logging::WARN(s.str());
    switch(m->type) {
        case MOTOR_COMMAND:
            //todo thread protect, maybe base on length or subtype
            std::memcpy(&command_in_, m->data, m->length);
            break;
    }
}