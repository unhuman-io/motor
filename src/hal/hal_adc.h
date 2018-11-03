#ifndef MOTOR_ADC_H
#define MOTOR_ADC_H

#include <cstdint>

namespace hal {
    class ADC {
    public:
        void get_adc() const;
        void set_adc();             ///< Used only for simulation
    };
}


#endif //MOTOR_ADC_H
