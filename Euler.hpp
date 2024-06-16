
template<typename Func>
void eulersA(Func f, double& y, double& v, double t, double h) {
    double y_derivative = f(t, y, v);
    y += h * y_derivative;
}