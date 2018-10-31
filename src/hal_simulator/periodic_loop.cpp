

#include "../hal/periodic_loop.h"
#include "easylogging++.h"
#include <chrono>
#include <thread>
#include <functional>

void PeriodicLoop::init(int32_t frequency_hz) {
    LOG(INFO) << "PeriodicLoop::init(" << frequency_hz << ")";

}