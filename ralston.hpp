#ifndef RALSTON_HPP
#define RALSTON_HPP

#include <functional>

template<typename Func1, typename Func2>
void calc(Func1 fx1, Func2 fx2, double& x1, double& x2, double& v1, double& v2, double h) {
    // Calculate k1 for x1 and x2
    double k1_x1 = h * v1;
    double k1_x2 = h * v2;

    // Calculate k1 for v1 and v2
    double k1_v1 = h * fx1(x1, x2, v1, v2);
    double k1_v2 = h * fx2(x1, x2, v1, v2);

    // Calculate k2 for x1 and x2
    double k2_x1 = h * (v1 + 3.0 / 4.0 * k1_v1);
    double k2_x2 = h * (v2 + 3.0 / 4.0 * k1_v2);

    // Calculate k2 for v1 and v2
    double k2_v1 = h * fx1(x1 + 3.0 / 4.0 * k1_x1, x2 + 3.0 / 4.0 * k1_x2, v1 + 3.0 / 4.0 * k1_v1, v2 + 3.0 / 4.0 * k1_v2);
    double k2_v2 = h * fx2(x1 + 3.0 / 4.0 * k1_x1, x2 + 3.0 / 4.0 * k1_x2, v1 + 3.0 / 4.0 * k1_v1, v2 + 3.0 / 4.0 * k1_v2);

    // Update positions and velocities using Ralston's method
    x1 += (1.0 / 3.0 * k1_x1 + 2.0 / 3.0 * k2_x1);
    x2 += (1.0 / 3.0 * k1_x2 + 2.0 / 3.0 * k2_x2);
    v1 += (1.0 / 3.0 * k1_v1 + 2.0 / 3.0 * k2_v1);
    v2 += (1.0 / 3.0 * k1_v2 + 2.0 / 3.0 * k2_v2);
}

#endif 
