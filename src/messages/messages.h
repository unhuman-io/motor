
#ifndef MOTOR_MESSAGES_H
#define MOTOR_MESSAGES_H

#include <stdint.h>

#define MAX_DATA_LENGTH 120 // bytes

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
    struct {
        float position;
    } measured;
} FOCStatus;

typedef struct {
    float position, velocity;
    float v_abc[3];
    FOCStatus foc_status;
} MotorStatus;

typedef struct {
    uint16_t type;       ///< \sa CommandType
    uint8_t data[MAX_DATA_LENGTH - 2];
} MotorCommand;

enum MessageType {
    MOTOR_COMMAND = 1,
};

typedef struct {
    uint16_t length;
    uint16_t type;      ///< \sa MessageType
    uint8_t data[MAX_DATA_LENGTH];
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