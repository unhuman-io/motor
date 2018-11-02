#ifndef MOTOR_ADC_H
#define MOTOR_ADC_H

#include <cstdint>

namespace hal {
    class ADC {
    public:
        void get_adc();
    private:
        uint16_t adc_result_[24];
    };
}


#endif //MOTOR_ADC_H
