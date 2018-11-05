
#include <messages.h>
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

#include <cstring>

void MainControlLoop::init(int32_t frequency_hz, FOCControlLoop &foc_control_loop, Communication &communication) {
    PeriodicLoop::init(frequency_hz);
    foc_control_loop_ = &foc_control_loop;
    communication_ = &communication;
}

void MainControlLoop::update() {
    PeriodicLoop::update();
    // communication
    MotorCommand &command = communication_->get_command();

    // sensor status
    FOCControlStatus foc_status;
    foc_control_loop_->get_status(&foc_status);

    // control
    //todo not always an foc_command
    FOCControlCommand foc_command;
    std::memcpy(&foc_command, &command.data, sizeof(foc_command));

    // act
    foc_control_loop_->set_command(foc_command);

    // status communication
    status_.motor_status.foc_status = foc_status.status;
    update_status();
}