#include "pi.hpp"
#include <cmath>

PI::PI(double min, double max, double dt, double kp, double ki)
{
    m_dt = dt;
    m_Kp = kp;
    m_Ki = ki;
    m_min = min;
    m_max = max;
}

double PI::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

double PI::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

double PI::calc_integr(double error)
{
    integral_temp += error * m_dt;
    double integr = m_Ki * integral_temp;
    return integr;
}

double PI::simulate(double pv)
{
    // Calculate controller output
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double integr = calc_integr(error);
    double output = prop + integr;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}
