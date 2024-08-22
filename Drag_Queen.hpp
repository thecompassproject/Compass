class drag
{
private:
    double _m, _r, _p, _mu, _c, _g, _method_choice, _x, _v;
    double A, B;

public:
    void input(double m, double r, double p, double mu, double c, double g, double x, double v, double method_choice)
    {
        _m = m;
        _r = r;
        _p = p;
        _mu = mu;
        _c = c;
        _g = g;
        _x = x;
        _v = v;
        _method_choice = method_choice;
    }

    float ono(double A, double v1, double B)
    {
        return _g - (((_p * 4 * atan(1) * _c * _r * _r) / (2 * _m)) * v1 * v1) - ((6 * 4 * atan(1) * _mu * _r * v1) / _m) - ((4 * _p * _r * _r * _r * 4 * atan(1) * _g) / (3 * _m));
    }

    float yoko(double A, double x1, double B1)
    {
        return B1;
    }

    void b()
    {
        double in, a;
        float h = 0.15;

        A = 0;
        B = 0;

        char *file_name = "drag.dat"; // give a default name to the file
        if (_method_choice == 1.0)
        {
            file_name = "drag_rk4.dat";
        }
        else if (_method_choice == 2.0)
        {
            file_name = "drag_euler.dat";
        }

        else if (_method_choice == 3.0)
        {
            file_name = "drag_rals.dat";
        }

        std::ofstream out(file_name);
        for (float t = 0.0; t > -1; t += h)
        {
            a = ono(A, _v, B);
            out << t << "  " << _x << "  " << _v << "  " << a << "\n";
            if (_method_choice == 1.0)
            {
                rk4A(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _x, _v, A, -h);
                rk4A(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _v, a, A, h);
            }

            else if (_method_choice == 2.0)
            {
                eulersA(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _x, _v, A, -h);
                eulersA(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _v, a, A, h);
            }

            else if (_method_choice == 3.0)
            {
                ralsA(std::bind(&drag::yoko, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _x, _v, A, -h);
                ralsA(std::bind(&drag::ono, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), _v, a, A, h);
            }

            else
            {
                std::cout << "ERROR !!Not any Method!! \n";
                break;
            }

            if (_x < 0)
            {
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

        std::string s;
        const char *ss = s.append("plot '").append(file_name).append("' using 1:2 with lines title 'Height'\n").c_str();
        const char *sss = s.append("replot '").append(file_name).append("' using 1:3 with lines title 'Velocity'\n").c_str();
        const char *ssss = s.append("replot '").append(file_name).append("' using 1:4 with lines title 'Velocity'\n").c_str();

        fprintf(gnuplotPipe, "set title 'Motion Of Spherical Body'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Height/Velocity/Acceleration'\n");
        // fprintf(gnuplotPipe, "plot 'drag1.dat' using 1:2 with lines title 'Height'\n");
        // fprintf(gnuplotPipe, "replot 'drag1.dat' using 1:3 with lines title 'Velocity'\n");
        // fprintf(gnuplotPipe, "replot 'drag1.dat' using 1:4 with lines title 'Acceleration'\n");

        fprintf(gnuplotPipe, ss);
        fprintf(gnuplotPipe, sss);
        fprintf(gnuplotPipe, ssss);

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
        return;
    }
};
