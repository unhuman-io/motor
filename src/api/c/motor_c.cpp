#include "motor_c.h"
#include "motor.h"

extern "C" {

    HMotor * create_motor() {
        return reinterpret_cast<HMotor*>(new Motor);
    }

    void send_message(HMotor *motor, Message *message) {
        reinterpret_cast<Motor *>(motor)->send_message(message);
    }

    float get_message(HMotor *motor) {
        return reinterpret_cast<Motor *>(motor)->get_message();
    }

    void destroy_motor(HMotor *motor) {
        delete reinterpret_cast<Motor *>(motor);
    }
}