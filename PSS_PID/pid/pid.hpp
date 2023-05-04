#ifndef PID_H
#define PID_H

#include "../siso/siso.hpp"

class PID : public SISO
{
public:
    PID(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5, double kd = 0.05);
    ~PID() = default;

    virtual double calc_error(double pv, double set_point) = 0;
    virtual double calc_prop(double error) = 0;
    virtual double calc_integr(double error) = 0;
    virtual double calc_deriv(double error) = 0;
    // virtual double calc_output(double prop, double integr, double deriv) = 0;
    virtual double calc_output(double pv, double set_point) = 0;

private:
    double m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
