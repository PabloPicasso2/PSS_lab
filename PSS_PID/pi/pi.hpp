#ifndef PI_H
#define PI_H

#include "../pid/pid.hpp"

class PI : public PID
{
public:
    double simulate(double x) override;

    PI(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5);
    ~PI() = default;

    double calc_error(double pv, double set_point) override;
    double calc_prop(double error) override;
    double calc_integr(double error) override;
    double calc_deriv(double error) override;
    // double calc_output(double prop, double integr, double deriv) override;
    double calc_output(double pv, double set_point) override;

private:
    double m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
