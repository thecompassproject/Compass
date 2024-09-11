class chaos
{
private:
    double _x, _y, _z, _rho, _beta, _sigma, _method_choice, _n, _h;

public:
    void input(double x, double y, double z, double sigma, double rho, double beta, double n, double h, double method_choice)
    {
        _sigma = sigma;
        _rho = rho;
        _beta = beta;
        _x = x;
        _y = y;
        _z = z;
        _n = n;
        _h = h;
        _method_choice = method_choice;
    }

    double fx(double A, double B, double C, double x1, double y1, double z1)
    {
        return _sigma * (y1 - x1);
    }

    double fy(double A, double B, double C, double x1, double y1, double z1)
    {
        return (x1 * (_rho - z1)) - y1;
    }

    double fz(double A, double B, double C, double x1, double y1, double z1)
    {
        return (x1 * y1) - (_beta * z1);
    }

    void sap()
    {

        char *file_name = "convection.dat"; // give a default name to the file
        if (_method_choice == 1.0)
        {
            file_name = "convection_rk4.dat";
        }
        else if (_method_choice == 2.0)
        {
            file_name = "convection_euler.dat";
        }
        else if (_method_choice == 3.0)
        {
            file_name = "convection_rals.dat";
        }

        std::ofstream out(file_name);

        for (double i = 0; i < _n; i++)
        {

            double A = 0.0;
            double B = 0.0;
            double C = 0.0;

            if (_method_choice == 1.0)
            {
                euler3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       A, B, C, _x, _y, _z, _h);
            }

            else if (_method_choice == 2.0)
            {
                ralston3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         A, B, C, _x, _y, _z, _h);
            }

            else if (_method_choice == 3.0)
            {
                rk43(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     A, B, C, _x, _y, _z, _h);
            }

            else
            {
                break;
            }

            out << _x << "  " << _y << "  " << _z << "\n";
        }

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
        const char *ss = s.append("splot '").append(file_name).append("' using 1:2:3 with lines title 'Convection of Fluids'\n").c_str();
        fprintf(gnuplotPipe, "set term wxt\n");
        fprintf(gnuplotPipe, "set title 'Lorenz Convection System'\n");
        fprintf(gnuplotPipe, "set xlabel 'X'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z'\n");
        fprintf(gnuplotPipe, ss);

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
        return;
    }
};