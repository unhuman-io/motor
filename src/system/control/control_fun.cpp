#include "control_fun.h"
#include "hal_fun.h"

float PIController::step(float desired, float measured) {
    float error = desired - measured;
    ki_sum_ += ki_ * error;
    ki_sum_ = hal::fsat(ki_sum_, ki_limit_);
    return kp_*error + ki_sum_;
}