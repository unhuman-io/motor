
#include "motor_c.h"
#include <stdio.h>
#include <unistd.h>

#include "string.h"

int main() {
    int i;
    HMotor *motor = create_motor_simulator();
    printf("msg: %f\n", get_message(motor));

    Message m;
    m.type = 1;
    m.length = 12;
    FOCCommand f;
    f.i_d = 0;
    f.i_q = 1.5;
    MotorCommand c;
    c.type = 1;
    memcpy(&c.data, &f, sizeof(FOCCommand));
    memcpy(&m.data, &c, sizeof(FOCCommand) + 2);
    send_message(motor, &m);

    for (i=0; i<30; i++) {
        usleep(100000);
        printf("position: %f\n", get_message(motor));
    }

    f.i_q = -3;
    memcpy(&c.data, &f, sizeof(FOCCommand));
    memcpy(&m.data, &c, sizeof(FOCCommand) + 2);
    send_message(motor, &m);

    for (i=0; i<30; i++) {
        usleep(100000);
        printf("position: %f\n", get_message(motor));
    }

    destroy_motor(motor);
    return 0;
}