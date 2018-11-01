
#include "motor_c.h"
#include <stdio.h>
#include <unistd.h>
int main() {
    int i;
    HMotor *motor = create_motor_simulator();
    printf("msg: %f\n", get_message(motor));

    for (i=0; i<30; i++) {
        usleep(100000);
        printf("position: %f\n", get_message(motor));
    }

    destroy_motor(motor);
    return 0;
}