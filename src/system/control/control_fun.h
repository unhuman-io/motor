#ifndef MOTOR_CONTROL_FUN_H
#define MOTOR_CONTROL_FUN_H


class PIController {
public:
    virtual float step(float desired, float measured);
private:
    float kp_, ki_, ki_sum_, ki_limit_;

};


#endif //MOTOR_CONTROL_FUN_H
