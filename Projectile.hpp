#ifdef _WIN32
#include <corecrt_math_defines.h> // to fix M_PI identifier not found error on windows OS
#endif

using namespace std;

class projectile
{
private:
    double _g, _p, _ax, _ay;
    double _method_choice, _m, _r, _V0, _th, _c;

public:
    void input(double method_choice, double m, double r, double V0, double th, double c)
    {
        _method_choice = method_choice;
        _m = m;
        _r = r;
        _V0 = V0;
        _th = (M_PI / 180.0) * th;
        _c = c;
        _g = -9.8;

        for (double i = 0; i < 1; i++)
        {
            if (_c == 0)
            {
                _m = 1;
                break;
            }
            _p = 1.22;
        }
    }

    double S(double X1, double Y1, double Vx1, double Vy1)
    {
        return -(((_p * 4 * atan(1) * _c * _r * _r) / (2 * _m)) * Vx1 * Vx1);
    }

    double A(double X11, double Y11, double Vx11, double Vy11)
    {
        return _g - (((_p * 4 * atan(1) * _c * _r * _r) / (2 * _m)) * Vy11 * Vy11);
    }

    string ND()
    {
        char *file_name = "projectile.dat"; // give a default name to the file
        if (_method_choice == 1.0)
        {
            file_name = "projectile_rk4.dat";
        }
        else if (_method_choice == 2.0)
        {
            file_name = "projectile_euler.dat";
        }

        else if (_method_choice == 3.0)
        {
            file_name = "projectile_rals.dat";
        }

        std::ofstream out(file_name);

        double X0 = 0.0;
        double Y0 = 0.0;
        double Vx = _V0 * cos(_th);
        double Vy = _V0 * sin(_th);
        double mh = pow((_V0 * sin(_th)), 2) / (2 * 9.8);

        double h = 0.001;
        for (double t = 0; t < 100; t += h)
        {
            out << X0 << "  " << Y0 << "\n";

            if (_method_choice == 1.0)
            {
                calc1(std::bind(&projectile::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&projectile::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      X0, Y0, Vx, Vy, h);
            }
            else if (_method_choice == 2.0)
            {
                calc4(std::bind(&projectile::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      std::bind(&projectile::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                      X0, Y0, Vx, Vy, h);
            }

            else if (_method_choice == 3.0)
            {
                calc(std::bind(&projectile::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     std::bind(&projectile::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
                     X0, Y0, Vx, Vy, h);
            }
            else
            {
                break;
            }

            if (Y0 < 0)
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
            return 0;
        }

        // Create plot command for gnuplot
        std::string s;
        const char *ss = s.append("plot '").append(file_name).append("' using 1:2 with lines title 'Trajectory'\n").c_str();

        fprintf(gnuplotPipe, "set title 'Projectile Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position (m)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position (m)'\n");
        fprintf(gnuplotPipe, ss);

        std::string response;
        const char *msg = response.append("The maximum height is: ").append(to_string(mh)).append(" m").c_str();

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif

        return msg;
    }
};
