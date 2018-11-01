

#include "../hal/periodic_loop.h"
#include "easylogging++.h"
#include <chrono>
#include <thread>
//#include <functional>

void run(PeriodicLoop *p, uint32_t interval_ns) {
    while(p->keep_running_) {
        p->step();
        std::this_thread::sleep_for(std::chrono::nanoseconds(interval_ns));
    }
}

PeriodicLoop::~PeriodicLoop() {
    keep_running_ = false;
    t->join();
}

void PeriodicLoop::init(int32_t frequency_hz) {
//    LOG(INFO) << "PeriodicLoop::init(" << frequency_hz << ")";
    int32_t interval_ns = 1e9*1.0/frequency_hz;
    std::cout << this << std::endl;
    t = new std::thread(run, this, interval_ns);
    //t->detach();
}

void PeriodicLoop::step() {
    std::ostringstream s; s << name() << "::step(), loop_count_: " << loop_count_++;
    logging::INFO(s.str());
}
