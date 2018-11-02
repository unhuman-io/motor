#ifndef MOTOR_PERIODIC_COMMUNICATION_H
#define MOTOR_PERIODIC_COMMUNICATION_H

template <class Command, class Param, class Status>
class PeriodicCommunication {
public:
    // TODO figure out if below can be used
    //    PeriodicCommunication() : Command(), Param(), Status() {}
    virtual void set_command(Command &command) { command_ = command;}
    virtual void set_param(Param &param) { param_ = param;}
    virtual void get_status(Status *status) const { *status = status_; }

    Command command_;
    Param param_;
    Status status_;
};


#endif //MOTOR_PERIODIC_COMMUNICATION_H
