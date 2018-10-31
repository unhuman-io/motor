#include "foc.h"
#include "easylogging++.h"
#include "hal_fun.h"

FOC::FOC() : command_(), param_() {}

void FOC::set_command(const FOCCommand &command) {
    hal::atomic_memcpy(&command_, &command, sizeof(command_));
}

void FOC::step() {
    LOG(INFO) << "FOC::step()";
}