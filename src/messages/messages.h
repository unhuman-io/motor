
#ifndef MOTOR_MESSAGES_H
#define MOTOR_MESSAGES_H

#include <stdint.h>

typedef struct {
    float kp;
    float ki;
    float ki_sat;
    float command_max;
} PIParam;

typedef struct {
    PIParam pi_d;
    PIParam pi_q;
    float current_filter_frequency_hz;
} FOCParam;

typedef struct {
    float i_d, i_q;
} FOCCommand;

typedef struct {
    struct {
        float i_d, i_q;
    } desired;
} FOCStatus;

typedef struct {
    float position, velocity;
    float v_abc[3];
} MotorStatus;

typedef struct {
    int16_t length;
} Message;


// Internal messages
typedef struct {
    int reserved;
} SystemUpdateCommand;

typedef struct {
    int reserved;
} SystemUpdateParam;

typedef struct {
    int reserved;
} SystemUpdateStatus;

typedef struct {
    int reserved;
} MainControlCommand;

typedef struct {
    int reserved;
} MainControlParam;

typedef struct {
    MotorStatus motor_status;
} MainControlStatus;

typedef struct {
    FOCCommand command;
} FOCControlCommand;

typedef struct {
    FOCParam param;
} FOCControlParam;

typedef struct {
    FOCStatus status;
} FOCControlStatus;

typedef struct {
    int reserved;
} SimulatorCommand;

typedef struct {
    int reserved;
} SimulatorParam;

typedef struct {
    MotorStatus motor_status;
} SimulatorStatus;

#endif