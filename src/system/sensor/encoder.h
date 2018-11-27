#ifndef MOTOR_ENCODER_H
#define MOTOR_ENCODER_H

#include "sensor.h"

class Encoder : public Sensor {
public:
    float get_position() const { return position_; }
    void set_position(float position) { position_ = position; }
private:
    float position_;
};


#endif //MOTOR_ENCODER_H
