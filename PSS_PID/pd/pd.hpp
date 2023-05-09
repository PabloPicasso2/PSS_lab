#ifndef PD_H
#define PD_H

#include "../siso/siso.hpp"

class PD : virtual public SISO
{
public:
    PD(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double kd = 0.05);
    ~PD() = default;

    double simulate(double pv) override;

    double calc_error(double pv, double set_point);
    double calc_prop(double error);
    double calc_deriv(double error);
    // double calc_output(double pv, double set_point) override;

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif