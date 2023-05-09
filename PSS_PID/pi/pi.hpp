#ifndef PI_H
#define PI_H

#include "../siso/siso.hpp"

class PI : virtual public SISO
{
public:
    PI(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5);
    ~PI() = default;
    
    double simulate(double pv) override;

    double calc_error(double pv, double set_point);
    double calc_prop(double error);
    double calc_integr(double error);
    // double calc_output(double pv, double set_point) override;

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
