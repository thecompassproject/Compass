#include <functional>
template<typename Func>
void fn(Func f, double& y, double& v, double t, double h) {
    double y_deri = f(t, y, v);
    y += (h/2.0) * y_deri;
}
