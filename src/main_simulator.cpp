
#include "system/system_update_loop.h"
#include "system/main_control_loop.h"
#include "system/foc_control_loop.h"
#include "system/communication.h"
#include "easylogging++.h"
#include "hal/hal_fun.h"
#include "hal/hal_pwm.h"
#include "hal_simulator/motor_simulator.h"
#include "hal_simulator/motor_simulator_voltage.h"
#include "messages.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

    hal::PWM pwm;
    MotorSimulator motor;
    MotorSimulatorVoltage motor_sim_voltage(&pwm);

    SystemUpdateLoop system_update_loop;
    MainControlLoop main_control_loop;
    FOCControlLoop foc_control_loop(&pwm);
    Communication communication;
    MotorStatus motor_status;

    system_update_loop.init();
    main_control_loop.init(10000);
    foc_control_loop.init(100000);

    // No FOC simulation
    for(int i=0; i<10; i++) {
        main_control_loop.step();
        motor.set_current(1, 2);
        motor.step();
        motor_status.position = motor.get_position();
        motor_status.velocity = motor.get_velocity();
        LOG(INFO) << "motor position: " << motor.get_position();
        LOG(INFO) << "motor_velocity: " << motor.get_velocity();
    }

    // With FOC simulation
    for(int i=0; i<10; i++) {
        foc_control_loop.step();
        motor_sim_voltage.step();
    }


    return 0;
}