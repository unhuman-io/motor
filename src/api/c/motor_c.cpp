#include "motor_c.h"
#include "motor.h"
#include "motor_simulator.h"

extern "C" {

    HMotor * create_motor() {
        return reinterpret_cast<HMotor*>(new Motor);
    }

    HMotor * create_motor_simulator() {
        return reinterpret_cast<HMotor*>(new MotorSimulator1);
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