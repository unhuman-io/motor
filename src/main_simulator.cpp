
#include "motor_simulator.h"
#include "easylogging++.h"
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#endif


int main() {
#ifdef _WIN32
    INIT_TERMINAL
#endif

    unhuman::MotorSimulator motor_simulator;

    std::this_thread::sleep_for(std::chrono::seconds(1000));

    return 0;
}