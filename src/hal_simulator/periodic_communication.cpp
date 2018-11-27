#include "periodic_communication.h"
#include <mutex>

typedef std::mutex mutex;

PeriodicCommunication::PeriodicCommunication() {
    command_mutex_ = new mutex;
    param_mutex_ = new mutex;
    status_mutex_ = new mutex;
}

PeriodicCommunication::~PeriodicCommunication() {
    delete command_mutex_;
    delete param_mutex_;
    delete status_mutex_;
}

void PeriodicCommunication::set_command(Command &command) { command_mutex_->lock(); command_in_ = command; command_mutex_->unlock(); }
// note try_lock below needs to succeed most of the time - maybe need higher frequency sub loops
void PeriodicCommunication::update_command() { if (command_mutex_->try_lock()) { command_ = command_in_; command_mutex_->unlock(); } }
// param maybe not worth worrying about
//void set_param(Param &param) { param_mutex_.lock(); param_in_ = param; param_mutex_.unlock(); }
void PeriodicCommunication::set_param(Param &param) { param_mutex_->lock(); param_ = param; param_mutex_->unlock(); }
void PeriodicCommunication::update_param() { param_mutex_->lock(); param_ = param_in_; param_mutex_->unlock(); }
void PeriodicCommunication::get_status(Status *status) { status_mutex_->lock(); *status = status_out_; status_mutex_->unlock(); }
void PeriodicCommunication::update_status() { status_mutex_->lock(); status_out_ = status_; status_mutex_->unlock(); }
