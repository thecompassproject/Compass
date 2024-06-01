#include <functional>
template<typename Func>
void euler(Func f, double& y, double& v, double t, double h) {
    double y_deri = f(t, y, v);
    y += h * y_deri;
}
