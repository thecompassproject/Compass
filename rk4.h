class rk4{
    public:
        static double rk4method(double a, double t, double (*rk4func)(double, double)) {
            double k1, k2, k3, k4, h;
            k1 = rk4func(a, t)*h;
            k2 = rk4func(a + (k1/2), t + (h/2))*h;
            k3 = rk4func(a + (k2/2), t + (h/2))*h;
            k4 = rk4func(a + k3, t + h)*h;
            return a + ((k1 + (2*k2) + (2*k3) + k4)/6);
        }
};