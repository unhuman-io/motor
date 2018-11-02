#include "../hal/hal_fun.h"
#include "easylogging++.h"
#include <cstring>
namespace hal {

    void atomic_memcpy(void *dest, const void *src, size_t n) {
        std::memcpy(dest, src, n);
    }

}