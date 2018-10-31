

#include "foc_control_loop.h"
#include "control/foc.h"

FOCControlLoop::FOCControlLoop() {
    foc_ = new FOC();
    FOCParam foc_param = {};
    foc_->set_param(foc_param);
}

FOCControlLoop::~FOCControlLoop() {
    delete foc_;
}

void FOCControlLoop::step() {
    FOCCommand foc_command = {};
    foc_->set_command(foc_command);
    foc_->step();
}