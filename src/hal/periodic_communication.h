#ifndef MOTOR_PERIODIC_COMMUNICATION_H
#define MOTOR_PERIODIC_COMMUNICATION_H

class mutex;

template <class Command, class Param, class Status>
class PeriodicCommunication {
public:
    PeriodicCommunication();
    virtual ~PeriodicCommunication();
    // TODO figure out if below can be used
    //    PeriodicCommunication() : Command(), Param(), Status() {}
    void set_command(Command &command);
    // note try_lock below needs to succeed most of the time - maybe need higher frequency sub loops
    void update_command();
    // param maybe not worth worrying about
    //void set_param(Param &param) { param_mutex_.lock(); param_in_ = param; param_mutex_.unlock(); }
    void set_param(Param &param);
    void update_param();
    void get_status(Status *status);
    void update_status();

    Command command_;
    Param param_;
    Status status_;
private:
    Command command_in_;
    Param param_in_;
    Status status_out_;
    mutex *command_mutex_;
    mutex *param_mutex_;
    mutex *status_mutex_;
};


#endif //MOTOR_PERIODIC_COMMUNICATION_H
