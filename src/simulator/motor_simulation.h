#ifndef MOTOR_MOTOR_SIMULATION_H
#define MOTOR_MOTOR_SIMULATION_H


class MotorSimulation {
public:
    MotorSimulation() : command_(), status_(), kt_(1), Im_(1) {}
    struct Command { float i; };
    struct Status { float position, velocity; };
    void set_command(const Command &command) { command_ = command; }
    void update();
    void get_status(Status *status) const { *status = status_; }
    void set_dt(float dt) { dt_ = dt; }
private:
    Command command_;
    Status status_;
    float kt_, Im_;
    float dt_;
};


#endif //MOTOR_MOTOR_SIMULATION_H
