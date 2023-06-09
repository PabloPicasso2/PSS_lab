#include "pi/pi.hpp"
#include "pd/pd.hpp"
#include <iostream>
#include "arx/arx.hpp"
#include "pid/pid.hpp"


/**
 * @brief
 *
 * @return int
 */
int main()
{
    auto pi = PI(0.0, 100.0, 0.1, 1.0, 0.1);
    auto arx = ARX({1.1, 1.2}, {1.3}, 0, 0);
    arx.save("config.csv");
    double y = 0.0;

    for (int i = 0; i < 30; i++)
    {
        auto u = pi.simulate(y);
        y = arx.simulate(u);
        std::cout << y << "\n";
    }

    std::cin.get();
}
