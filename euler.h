#include <functional>

template<typename Func>
void euler(Func f, double& y, double& v, double t, double h) {
    double y_derivative = f(t, y, v);
    y += h * y_derivative;
}