#include "../hal/hal_fun.h"
//#include "easylogging++.h"
#include <cstring>
#include <cmath>

namespace hal {

    void atomic_memcpy(void *dest, const void *src, size_t n) {
        std::memcpy(dest, src, n);
    }

    float fsat(float value, float limit) {
        return std::fmin(value, std::fmax(value, -limit));
    }

}