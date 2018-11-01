#include "system.h"

#include "system_update_loop.h"
#include "main_control_loop.h"
#include "foc_control_loop.h"
#include "communication.h"

#include "hal_fun.h"
#include "hal_pwm.h"

#include "messages.h"
#include "easylogging++.h"

//INITIALIZE_EASYLOGGINGPP

System::System() {
 //   el::Loggers::
    hal::PWM pwm;
    //   MotorSimulator motor;
    //   MotorSimulatorVoltage motor_sim_voltage(&pwm);

    SystemUpdateLoop system_update_loop;
    MainControlLoop main_control_loop;
    FOCControlLoop foc_control_loop(&pwm);
    Communication communication;
    MotorStatus motor_status;

    system_update_loop.init();
    main_control_loop.init(3);
    foc_control_loop.init(10);
}
