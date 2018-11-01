
#include "system_update_loop.h"
#include "easylogging++.h"

void SystemUpdateLoop::init() {
    logging::INFO("SystemUpdateLoop::init()");
    PeriodicLoop::init(5);
}