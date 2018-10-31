

#ifndef MOTOR_PERIODICLOOP_H
#define MOTOR_PERIODICLOOP_H


class PeriodicLoop {
public:
    virtual void init();
    virtual void step() {}
};


#endif //MOTOR_PERIODICLOOP_H
