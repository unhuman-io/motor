
#include "motor_simulator.h"
#include "easylogging++.h"
#include <chrono>
#include <thread>


int main() {

    unhuman::MotorSimulator motor_simulator;

    std::this_thread::sleep_for(std::chrono::seconds(1000));

    return 0;
}