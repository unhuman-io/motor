
#ifndef MOTOR_MESSAGES_H
#define MOTOR_MESSAGES_H

typedef struct {
    float kp;
    float ki;
    float ki_sat;
} PIParam;

typedef struct {
    PIParam pi_d;
    PIParam pi_q;
} FOCParam;

typedef struct {
    float i_d, i_q;
} FOCCommand;

typedef struct {
    float position, velocity;
} MotorStatus;

typedef struct {
    int length;
} Message;

#endif