class double_pendulum
{
private:
    double _g, _m1, _m2, _l1, _l2, _o11, _o22, _method_choice;

public:
    void input(double m1, double m2, double l1, double l2, double o11, double o22, double g, double method_choice)
    {
        _o11 = o11 * (M_PI / 180);
        _o22 = o22 * (M_PI / 180);
        _m1 = m1;
        _m2 = m2;
        _l1 = l1;
        _l2 = l2;
        _g = g;
        _method_choice = method_choice;
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

        char *file_name = "pendulum.dat"; // give a default name to the file
        if (_method_choice == 1.0)
        {
            file_name = "pendulum_rk4.dat";
        }
        else if (_method_choice == 2.0)
        {
            file_name = "pendulum_euler.dat";
        }

        else if (_method_choice == 3.0)
        {
            file_name = "pendulum_rals.dat";
        }

        std::ofstream out(file_name);

        for (double i = 0; i < 50000; i++)
        {

            out << _o11 << "  " << meg11 << "  " << _o22 << "  " << meg22 << "\n";
            if (_method_choice == 1.0)
            {
                calc1(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      _o11, _o22, meg11, meg22, h);
            }

            else if (_method_choice == 2.0)
            {
                calc4(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      _o11, _o22, meg11, meg22, h);
            }

            else if (_method_choice == 3.0)
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
        out.close();

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

        // Create plot command for gnuplot
        std::string s;
        const char *ss = s.append("plot '").append(file_name).append("' using 1:2 with lines title 'Pendulum 1'\n").c_str();
        std::string sss;
        const char *ssss = sss.append("replot '").append(file_name).append("' using 3:4 with lines title 'Pendulum 2'\n").c_str();

        fprintf(gnuplotPipe, "set term wxt\n");
        fprintf(gnuplotPipe, "set title 'Double Pendulum Phase Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'Angular Displacement'\n");
        fprintf(gnuplotPipe, "set ylabel 'Angular Velocity'\n");
        fprintf(gnuplotPipe, ss);
        fprintf(gnuplotPipe, ssss);
        // fprintf(gnuplotPipe, "plot 'tra.dat' using 1:2 with lines title 'Mass^1'\n");
        // fprintf(gnuplotPipe, "replot 'tra.dat' using 3:4 with lines title 'Mass^2'\n");

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
    }
};
