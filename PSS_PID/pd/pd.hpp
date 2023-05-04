#ifndef PD_H
#define PD_H

#include "../pid/pid.hpp"

class PD : public PID
{
    PD(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double kd = 0.05);
    ~PD() = default;

    double calc_error(double pv, double set_point) override;
    double calc_prop(double error) override;
    double calc_deriv(double error) override;
    // double calc_output(double prop, double integr, double deriv) override;
    double calc_output(double pv, double set_point) override;

private:
    double m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
