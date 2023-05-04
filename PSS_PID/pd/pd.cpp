#include "pd.hpp"
#include <cmath>

PD::PD(double min, double max, double dt, double kp, double kd)
{
    // double m_kp = kp, m_ti = ti, m_td = td;
    m_dt = dt;
    m_Kp = kp;
    m_Kd = kd;
    m_min = min;
    m_max = max;
}

double PD::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

double PD::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

double PD::calc_deriv(double error)
{
    double deriv = m_Kd * ((error - prev_error) / m_dt);
    // Save error to previous error
    prev_error = error;

    return deriv;
}

double PD::calc_output(double pv, double set_point)
{
    // Calculate controller output
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double deriv = calc_deriv(error);
    double output = prop + deriv;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}