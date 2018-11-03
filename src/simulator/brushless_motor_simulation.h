#ifndef MOTOR_BRUSHLESS_MOTOR_SIMULATION_H
#define MOTOR_BRUSHLESS_MOTOR_SIMULATION_H


class BrushlessMotorSimulation {
public:
    struct Command { float v_abc[3]; };
    struct Status { float i_q, position, velocity; };
    void set_command(const Command &command) { command_ = command; }
    void update();
    void get_status(Status *status) const { *status = status_; }
private:
    Command command_;
    Status status_;
};


#endif //MOTOR_BRUSHLESS_MOTOR_SIMULATION_H
