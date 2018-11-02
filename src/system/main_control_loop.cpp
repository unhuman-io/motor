
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

void MainControlLoop::init(int32_t frequency_hz, FOCControlLoop &foc_control_loop, Communication &communication) {
    PeriodicLoop::init(frequency_hz);
    foc_control_loop_ = &foc_control_loop;
    communication_ = &communication;
}

void MainControlLoop::update() {
    PeriodicLoop::update();
    // communication

    // sensor status
    FOCControlStatus foc_status;
    foc_control_loop_->get_status(&foc_status);

    // control
    FOCControlCommand foc_command;

    // act
    foc_control_loop_->set_command(foc_command);

}