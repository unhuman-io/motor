
struct PIParam {
    float kp;
    float ki;
    float ki_sat;
};

struct FOCParam {
    PIParam pi_d;
    PIParam pi_q;
};

struct FOCCommand {
    float i_d, i_q;
};