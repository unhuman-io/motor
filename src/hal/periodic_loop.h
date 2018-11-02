

#ifndef MOTOR_PERIODICLOOP_H
#define MOTOR_PERIODICLOOP_H

#include <cstdint>
#include <atomic>
#include <string>

#include <thread>

class PeriodicLoop {
public:
    PeriodicLoop() : loop_count_(0), keep_running_(true) {}
    virtual ~PeriodicLoop();
    void init(int32_t frequency_hz);
    virtual void update();

    virtual std::string name() { return "PeriodicLoop"; }
    std::atomic_bool keep_running_;
private:
    uint64_t loop_count_;
    std::thread *t;

};


#endif //MOTOR_PERIODICLOOP_H
