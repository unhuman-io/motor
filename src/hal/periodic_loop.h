

#ifndef MOTOR_PERIODICLOOP_H
#define MOTOR_PERIODICLOOP_H

#include <cstdint>

class PeriodicLoop {
public:
    virtual void init(int32_t frequency_hz);
    virtual void step() {}
};


#endif //MOTOR_PERIODICLOOP_H
