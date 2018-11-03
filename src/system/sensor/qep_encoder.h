#ifndef MOTOR_QEP_ENCODER_H
#define MOTOR_QEP_ENCODER_H

#include "encoder.h"

namespace hal {
    class QEP;
}
class QEPEncoder : public Encoder {
private:
    hal::QEP *qep;
};


#endif //MOTOR_QEP_ENCODER_H
