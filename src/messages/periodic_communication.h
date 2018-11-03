#ifndef MOTOR_PERIODIC_COMMUNICATION_H
#define MOTOR_PERIODIC_COMMUNICATION_H

#include <mutex>

template <class Command, class Param, class Status>
class PeriodicCommunication {
public:
    // TODO figure out if below can be used
    //    PeriodicCommunication() : Command(), Param(), Status() {}
    void set_command(Command &command) { command_mutex_.lock(); command_in_ = command; command_mutex_.unlock(); }
    // note try_lock below needs to succeed most of the time - maybe need higher frequency sub loops
    void update_command() { if(command_mutex_.try_lock()) { command_ = command_in_; command_mutex_.unlock(); } }
    // param maybe not worth worrying about
    //void set_param(Param &param) { param_mutex_.lock(); param_in_ = param; param_mutex_.unlock(); }
    void set_param(Param &param) { param_mutex_.lock(); param_ = param; param_mutex_.unlock(); }
    void update_param() { param_mutex_.lock(); param_ = param_in_; param_mutex_.unlock(); }
    void get_status(Status *status) { status_mutex_.lock(); *status = status_out_; status_mutex_.unlock(); }
    void update_status() { status_mutex_.lock(); status_out_ = status_; status_mutex_.unlock(); }

    Command command_;
    Param param_;
    Status status_;
private:
    Command command_in_;
    Param param_in_;
    Status status_out_;
    std::mutex command_mutex_;
    std::mutex param_mutex_;
    std::mutex status_mutex_;
};


#endif //MOTOR_PERIODIC_COMMUNICATION_H
