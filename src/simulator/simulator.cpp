#include <messages.h>
#include "simulator.h"

#include "system.h"
#include "hal_adc.h"
#include "motor_simulation.h"
#include "sensor/encoder.h"
#include "communication.h"


Simulator::Simulator(System &system) : system_(system), position_(), velocity_() {
    motor_simulation_ = new MotorSimulation;
    motor_simulation_->set_dt(get_dt());
}

Simulator::~Simulator() {
    delete motor_simulation_;
}

void Simulator::send_message(Message *m) {
    system_.communication_->send_message(m);
}

void Simulator::init(int32_t frequency_hz) {
    PeriodicLoop::init(frequency_hz);
}

void Simulator::update() {
    update_command();
    status_.motor_status = system_.get_status();
//
//   // BrushlessMotorSimulation::Command command;// = { .v_abc[0] = status_.motor_status.v_abc[0],
//                                              //    .v_abc[1] = status_.motor_status.v_abc[1],
//                                               //   .v_abc[2] = status_.motor_status.v_abc[2]};
//    command.v_abc[0] = status_.motor_status.v_abc[0];
//    command.v_abc[1] = status_.motor_status.v_abc[1];
//    command.v_abc[2] = status_.motor_status.v_abc[2];

    MotorSimulation::Command command;
    command.i = status_.motor_status.foc_status.desired.i_q;

    motor_simulation_->set_command(command);
    motor_simulation_->update();
    MotorSimulation::Status status;
    motor_simulation_->get_status(&status);

    //TODO below is temporary status force, should be done through hal
    status_.motor_status.position = status.position;
    status_.motor_status.velocity = status.velocity;
    update_status();
    // update sensors
    system_.adc_->set_adc();
    system_.motor_encoder_->set_position(status.position);
}

float Simulator::get_position() const { return position_; }

float Simulator::get_velocity() const { return velocity_; }
