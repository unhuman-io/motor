#include "simulator.h"

#include "easylogging++.h"
#include "system.h"
#include "hal_adc.h"
#include "brushless_motor_simulation.h"


Simulator::Simulator(System &system) : system_(system), position_(), velocity_(), i_d_(),
                                                                i_q_() {
    motor_simulation_ = new BrushlessMotorSimulation;
}

Simulator::~Simulator() {
    delete motor_simulation_;
}

void Simulator::init(int32_t frequency_hz) {
    PeriodicLoop::init(frequency_hz);
}

void Simulator::set_current(float i_d, float i_q) {
    i_d_ = i_d;
    i_q_ = i_q;
}

void Simulator::update() {
    update_command();
    status_.motor_status = system_.get_status();

    BrushlessMotorSimulation::Command command;// = { .v_abc[0] = status_.motor_status.v_abc[0],
                                              //    .v_abc[1] = status_.motor_status.v_abc[1],
                                               //   .v_abc[2] = status_.motor_status.v_abc[2]};
    command.v_abc[0] = status_.motor_status.v_abc[0];
    command.v_abc[1] = status_.motor_status.v_abc[1];
    command.v_abc[2] = status_.motor_status.v_abc[2];

    motor_simulation_->set_command(command);
    motor_simulation_->update();
    BrushlessMotorSimulation::Status status;
    motor_simulation_->get_status(&status);

    //TODO below is temporary status force
    status_.motor_status.position = status.position;
    status_.motor_status.velocity = status.velocity;
    update_status();
    // update sensors
    system_.adc_->set_adc();
}

float Simulator::get_position() const { return position_; }

float Simulator::get_velocity() const { return velocity_; }
