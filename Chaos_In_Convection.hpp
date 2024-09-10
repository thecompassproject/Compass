class chaos
{
private:
    double _x, _y, _z, _r, _bt, _sig, _method_choice;

public:
    void input(double x, double y, double z, double method_choice)
    {
        _r = 28;
        _bt = 2.667;
        _sig = 10;
        _x = x;
        _y = y;
        _z = z;
        _method_choice = method_choice;
    }

    double fx(double A, double B, double C, double x1, double y1, double z1)
    {
        return _sig * (y1 - x1);
    }

    double fy(double A, double B, double C, double x1, double y1, double z1)
    {
        return (x1 * (_r - z1)) - y1;
    }

    double fz(double A, double B, double C, double x1, double y1, double z1)
    {
        return (x1 * y1) - (_bt * z1);
    }

    void sap()
    {
        double h = 0.01;
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

        for (double i = 0; i < 10000; i++)
        {

            double A = 0.0;
            double B = 0.0;
            double C = 0.0;

            if (_method_choice == 1.0)
            {
                euler3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                       A, B, C, _x, _y, _z, h);
            }

            else if (_method_choice == 2.0)
            {
                ralston3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                         A, B, C, _x, _y, _z, h);
            }

            else if (_method_choice == 3.0)
            {
                rk43(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
                     A, B, C, _x, _y, _z, h);
            }

            else
            {
                // std::cout<<"ERROR !!Not any Method!!:: \n";
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
        const char *ss = s.append("plot '").append(file_name).append("' using 1:3 with lines title 'Convection in XZ Plane'\n").c_str();
        // std::string sss;
        // const char *ssss = sss.append("resplot '").append(file_name).append("' using 2:3 with lines title 'Convection YZ'\n").c_str();
        // std::string sssss;
        // const char *ssssss = sssss.append("resplot '").append(file_name).append("' using 1:3 with lines title 'Convection XZ'\n").c_str();

        fprintf(gnuplotPipe, "set title 'Convection in Fluids'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position'\n");
        // fprintf(gnuplotPipe, "set ylabel 'Y Position'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z Position'\n");
        // fprintf(gnuplotPipe, "splot 'chaos.dat' using 1:2:3 with lines title 'Trajectory'\n");
        fprintf(gnuplotPipe, ss);
        // fprintf(gnuplotPipe, ssss);
        // fprintf(gnuplotPipe, ssssss);

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
        return;
    }
};
