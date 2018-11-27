
#include "motor_c.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep(1000*x)
#endif

#include "string.h"

int main() {
    int i;
    // get color output on windows
#ifdef _WIN32
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD old_mode;
    GetConsoleMode(hStdout, &old_mode);
    SetConsoleMode(hStdout, old_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

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
        Sleep(100);
        printf("position: %f\n", get_message(motor));
    }

    f.i_q = -3;
    memcpy(&c.data, &f, sizeof(FOCCommand));
    memcpy(&m.data, &c, sizeof(FOCCommand) + 2);
    send_message(motor, &m);

    for (i=0; i<30; i++) {
        Sleep(100);
        printf("position: %f\n", get_message(motor));
    }

    destroy_motor(motor);
    return 0;
}