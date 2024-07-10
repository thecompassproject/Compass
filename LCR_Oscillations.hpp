class LCR
{
private:
    double _L, _C, _R, _h, _val;
    double _initialTime, _finalTime, _I, _Q;
    int _n;

public:
    string input(double val, double L, double C, double R)
    {
        _L = 1e-3 * L;
        _C = 1e-6 * C;
        _R = R;
        _val = val;

        if (pow(_R, 2) > (4 * _L) / (1000 * _C))
        {
            // std::cout << "\nThe oscillator is over-damped.";
            return "Message: The oscillator is over-damped.";
        }

        else if (pow(_R, 2) < (4 * _L) / (1000 * _C))
        {
            cout << pow(_R, 2) << "\n";
            cout << (4 * _L) / _C;
            return "Message: The oscillator is under-damped.";
        }

        else
        {
            return "Message: The oscillator is critically-damped.";
        }
    }
    // Wrapper function to match the required signature
    double f_wrapper(double A, double B, double Q1, double I1)
    {
        return -(((Q1 / _C) + (_R * I1)) / _L);
    }

    double cha_wrapper(double A, double B, double Q1, double I1)
    {
        return I1;
    }

    void kart(double initialTime, double finalTime, double I, double Q, int n)
    {
        _finalTime = 1e-6 * finalTime;
        _I = 1e-3 * I;
        _Q = 1e-3 * Q;
        _n = n;
        _initialTime = 0.0;
        double h = (_finalTime - _initialTime) / _n;

        char *file_name = "lcr.dat";
        if (_val == 1.0)
        {
            file_name = "lcr_rk4.dat";
        }
        else if (_val == 2.0)
        {
            file_name = "lcr_euler.dat";
        }
        else if (_val == 3.0)
        {
            file_name = "lcr_rals.dat";
        }

        std::ofstream out(file_name);

        // A and B are dummy variables for the sake of compatibility
        double A = 0;
        double B = 0;

        for (double t = _initialTime; t <= _finalTime; t += h)
        {
            // steps calculating is replaced by function call from included header file
            if (_val == 1.0)
            {
                calc1(std::bind(&LCR::cha_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&LCR::f_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      A, B, _Q, _I, h);
            }

            else if (_val == 2.0)
            {
                calc4(std::bind(&LCR::cha_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&LCR::f_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      A, B, _Q, _I, h);
            }

            else if (_val == 3.0)
            {
                calc(std::bind(&LCR::cha_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     std::bind(&LCR::f_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     A, B, _Q, _I, h);
            }

            else
            {
                std::cout << "ERROR !!Not Any Method!!\n";
                break;
            }

            out << t << "  " << _I << "  " << _Q << "\n";
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
        const char *ss = s.append("plot '").append(file_name).append("' using 1:2 with lines title 'Current'\n").c_str();

        if (pow(_R, 2) > (4 * _L) / _C)
        {
            fprintf(gnuplotPipe, "set title 'Over Damped'\n");
            fprintf(gnuplotPipe, "set xlabel 'Time'\n");
            fprintf(gnuplotPipe, "set ylabel 'Current'\n");
            fprintf(gnuplotPipe, ss);
        }
        else if (pow(_R, 2) < (4 * _L) / _C)
        {
            fprintf(gnuplotPipe, "set title 'Under Damped'\n");
            fprintf(gnuplotPipe, "set xlabel 'Time'\n");
            fprintf(gnuplotPipe, "set ylabel 'Current'\n");
            fprintf(gnuplotPipe, ss);
        }
        else
        {
            fprintf(gnuplotPipe, "set title 'Critically Damped'\n");
            fprintf(gnuplotPipe, "set xlabel 'Time'\n");
            fprintf(gnuplotPipe, "set ylabel 'Current'\n");
            fprintf(gnuplotPipe, ss);
        }

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif

        return;
    }
};