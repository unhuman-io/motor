
#include "system/system_update_loop.h"
#include "system/main_control_loop.h"
#include "system/foc_control_loop.h"
#include "system/communication.h"
#include "easylogging++.h"
#include "hal/hal_fun.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

    SystemUpdateLoop system_update_loop;
    MainControlLoop main_control_loop;
    FOCControlLoop foc_control_loop;
    Communication communication;

    system_update_loop.init();
    main_control_loop.init();
    foc_control_loop.init();


    for(int i=0; i<10; i++) {
        foc_control_loop.step();
    }


    return 0;
}