#ifndef MOTOR_PERIODIC_COMMUNICATION_H
#define MOTOR_PERIODIC_COMMUNICATION_H

template <class Command, class Param, class Status>
class PeriodicCommunication {
public:
    // TODO figure out if below can be used
    //    PeriodicCommunication() : Command(), Param(), Status() {}
    void set_command(Command &command) { command_in_ = command;  }
    // note try_lock below needs to succeed most of the time - maybe need higher frequency sub loops
    void update_command() {  command_ = command_in_;  }
    // param maybe not worth worrying about
    //void set_param(Param &param) { param_mutex_.lock(); param_in_ = param; param_mutex_.unlock(); }
    void set_param(Param &param) { param_ = param;  }
    void update_param() { param_ = param_in_; }
    void get_status(Status *status) { *status = status_out_; }
    void update_status() { status_out_ = status_; }

    Command command_;
    Param param_;
    Status status_;
private:
    Command command_in_;
    Param param_in_;
    Status status_out_;
};


#endif //MOTOR_PERIODIC_COMMUNICATION_H
