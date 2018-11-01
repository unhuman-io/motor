#ifndef MOTOR_SYSTEM_H
#define MOTOR_SYSTEM_H

class SystemUpdateLoop;
class MainControlLoop;
class FOCControlLoop;
class Communication;

class System {
public:
    System();
    ~System();
private:
    SystemUpdateLoop *system_update_loop_;
    MainControlLoop *main_control_loop_;
    FOCControlLoop *foc_control_loop_;
    Communication *communication_;
};

#endif //MOTOR_SYSTEM_H
