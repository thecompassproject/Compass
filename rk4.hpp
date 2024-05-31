#include <functional>

template<typename Func>
void calc2(Func f, double& y,double& v ,double t, double h) {
    
    double k1 = h * f(t,y,v);
    double k2 = h * f(t + 0.5 * h, y + 0.5 * k1,v + 0.5 * k1);
    double k3 = h * f(t + 0.5 * h, y + 0.5 * k2,v + 0.5 * k2);
    double k4 = h * f(t + h, y + k3,v + k3);
    y += (1.0 / 6.0 * k1 + 1.0 / 3.0 * k2 + 1.0 / 3.0 * k3 + 1.0 / 6.0 * k4);
}