#ifndef RK4_HPP
#define RK4_HPP

#include <functional>

template<typename Func1, typename Func2>
void calc1(Func1 fx1, Func2 fx2, double& x1, double& x2, double& v1, double& v2, double h) {
    // Calculate k1 for x1 and x2
    double k1_x1 = h * v1;
    double k1_x2 = h * v2;

    // Calculate k1 for v1 and v2
    double k1_v1 = h * fx1(x1, x2, v1, v2);
    double k1_v2 = h * fx2(x1, x2, v1, v2);

    // Calculate k2 for x1 and x2
    double k2_x1 = h * (v1 + 0.5 * k1_v1);
    double k2_x2 = h * (v2 + 0.5 * k1_v2);

    // Calculate k2 for v1 and v2
    double k2_v1 = h * fx1(x1 + 0.5 * k1_x1, x2 + 0.5 * k1_x2, v1 + 0.5 * k1_v1, v2 + 0.5 * k1_v2);
    double k2_v2 = h * fx2(x1 + 0.5 * k1_x1, x2 + 0.5 * k1_x2, v1 + 0.5 * k1_v1, v2 + 0.5 * k1_v2);

    // Calculate k3 for x1 and x2
    double k3_x1 = h * (v1 + 0.5 * k2_v1);
    double k3_x2 = h * (v2 + 0.5 * k2_v2);

    // Calculate k3 for v1 and v2
    double k3_v1 = h * fx1(x1 + 0.5 * k2_x1, x2 + 0.5 * k2_x2, v1 + 0.5 * k2_v1, v2 + 0.5 * k2_v2);
    double k3_v2 = h * fx2(x1 + 0.5 * k2_x1, x2 + 0.5 * k2_x2, v1 + 0.5 * k2_v1, v2 + 0.5 * k2_v2);

    // Calculate k4 for x1 and x2
    double k4_x1 = h * (v1 + k3_v1);
    double k4_x2 = h * (v2 + k3_v2);

    // Calculate k4 for v1 and v2
    double k4_v1 = h * fx1(x1 + k3_x1, x2 + k3_x2, v1 + k3_v1, v2 + k3_v2);
    double k4_v2 = h * fx2(x1 + k3_x1, x2 + k3_x2, v1 + k3_v1, v2 + k3_v2);

    // Update positions and velocities using RK4 method
    x1 += (1.0 / 6.0 * k1_x1 + 1.0 / 3.0 * k2_x1 + 1.0 / 3.0 * k3_x1 + 1.0 / 6.0 * k4_x1);
    x2 += (1.0 / 6.0 * k1_x2 + 1.0 / 3.0 * k2_x2 + 1.0 / 3.0 * k3_x2 + 1.0 / 6.0 * k4_x2);
    v1 += (1.0 / 6.0 * k1_v1 + 1.0 / 3.0 * k2_v1 + 1.0 / 3.0 * k3_v1 + 1.0 / 6.0 * k4_v1);
    v2 += (1.0 / 6.0 * k1_v2 + 1.0 / 3.0 * k2_v2 + 1.0 / 3.0 * k3_v2 + 1.0 / 6.0 * k4_v2);
}

#endif // RK4_HPP
