#ifndef MOTOR_MOTORC_H
#define MOTOR_MOTORC_H

#include "messages.h"

#ifdef __cplusplus
extern "C" {
#endif

struct HMotor;
typedef struct HMotor HMotor;

HMotor * create_motor();
HMotor * create_motor_simulator();
void send_message(HMotor *motor, Message *message);
float get_message(HMotor *);
void destroy_motor(HMotor *);

#ifdef __cplusplus
};
#endif

#endif //MOTOR_MOTORC_H
