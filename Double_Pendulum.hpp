class double_pendulum
{
private:
    double _g, _m1, _m2, _l1, _l2, _o11, _o22, _val;

public:
    void input(double m1, double m2, double l1, double l2, double o11, double o22, double g, double val)
    {
        _o11 = o11 * (M_PI / 180);
        _o22 = o22 * (M_PI / 180);
        _m1 = m1;
        _m2 = m2;
        _l1 = l1;
        _l2 = l2;
        _g = g;
        _val = val;
    }
    double ac1(double th1, double th2, double og1, double og2)
    {
        return (-_g * (2 * _m1 + _m2) * sin(th1) - _m2 * _g * sin(th1 - 2 * th2) - 2 * sin(th1 - th2) * _m2 * (og2 * og2 * _l2 + og1 * og1 * _l1 * cos(th1 - th2))) / (_l1 * (2 * _m1 + _m2 - _m2 * cos(2 * th1 - 2 * th2)));
    }
    double ac2(double th1, double th2, double og1, double og2)
    {
        return (2 * sin(th1 - th2) * (og1 * og1 * _l1 * (_m1 + _m2) + _g * (_m1 + _m2) * cos(th1) + og2 * og2 * _l2 * _m2 * cos(th1 - th2))) / (_l2 * (2 * _m1 + _m2 - _m2 * cos(2 * th1 - 2 * th2)));
    }
    void yo()
    {
        double meg11 = 0;
        double meg22 = 0;
        double h = 0.0005;
        std::ofstream outfl("tra.dat");
        for (double i = 0; i < 20000; i++)
        {
            double x11 = _l1 * sin(_o11);
            double y11 = -_l1 * cos(_o11);
            double x22 = x11 + (_l2 * sin(_o22));
            double y22 = y11 - (_l2 * cos(_o22));
            outfl << x11 << "  " << y11 << "  " << x22 << "  " << y22 << "\n";
            if (_val == 1.0)
            {
                calc1(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      _o11, _o22, meg11, meg22, h);
            }

            else if (_val == 2.0)
            {
                calc4(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      _o11, _o22, meg11, meg22, h);
            }

            else if (_val == 3.0)
            {
                calc(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     _o11, _o22, meg11, meg22, h);
            }

            else
            {
                std::cout << "ERROR !!Not any type!!\n";
                break;
            }
        }
        outfl.close();

        // Important if building for both Unix and Windows OS
        // Plot the data using gnuplot
#ifdef _WIN32
        FILE *gnuplotPipe = _popen("gnuplot -persistent", "w");
#else
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
#endif

        if (!gnuplotPipe)
        {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }
        fprintf(gnuplotPipe, "set size ratio -1 \n");
        fprintf(gnuplotPipe, "set title 'Double Pendulum Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position'\n");
        fprintf(gnuplotPipe, "plot 'tra.dat' using 1:2 with lines title 'Mass^1'\n");
        fprintf(gnuplotPipe, "replot 'tra.dat' using 3:4 with lines title 'Mass^2'\n");

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
    }
};
