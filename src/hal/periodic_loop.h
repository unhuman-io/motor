

#ifndef MOTOR_PERIODICLOOP_H
#define MOTOR_PERIODICLOOP_H

#include <cstdint>
#include <iostream>

#include <thread>
#include <atomic>

class PeriodicLoop {
public:
    PeriodicLoop() : loop_count_(0), keep_running_(true) { std::cout << "p const\n"; }
    ~PeriodicLoop();
    virtual void init(int32_t frequency_hz);
    virtual void step();
    void test();
    std::atomic_bool keep_running_;
private:
    uint64_t loop_count_;
    std::thread *t;

};


#endif //MOTOR_PERIODICLOOP_H
