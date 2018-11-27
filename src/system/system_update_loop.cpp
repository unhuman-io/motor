
#include "system_update_loop.h"
#include "logging.h"

void SystemUpdateLoop::init() {
    logging::INFO("SystemUpdateLoop::init()");
    PeriodicLoop::init(5);
}