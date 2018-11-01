
#include "motor_c.h"
#include <stdio.h>
#include <unistd.h>
int main() {
    HMotor *motor = create_motor_simulator();
    printf("msg: %f\n", get_message(motor));

    sleep(1);
    destroy_motor(motor);
    return 0;
}