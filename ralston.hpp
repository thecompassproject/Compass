

template<typename Func>
void ralsA(Func f, double& y,double& v, double t, double h) {
    
    double k1 = h * f(t,y,v);
    double k2 = h * f(t + 3.0 / 4.0 * h, y + 3.0 / 4.0 * k1, v + 3.0 / 4.0 * k1);
    y += (1.0 / 3.0 * k1 + 2.0 / 3.0 * k2);
}