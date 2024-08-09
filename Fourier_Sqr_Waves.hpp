class fourier
{
private:
    int _n, _loop_count, i, k;
    float p, omega, _a, sum, fs, _time_period;

public:
    void input(double n, double time_period, double a, double loop_count)
    {
        _n = n;
        _time_period = time_period;
        _a = a;
        _loop_count = loop_count;
        // std::cout << "enter the value of n for no.of sin waves to be superimposed:";
        // std::cin >> n;
        // std::cout << "\nenter the value of timeperiod of square wave:";
        // std::cin >> timp;
        // std::cout << "\nenter the value of amplitude:";
        // std::cin >> a;
        // std::cout << "\nenter the no.of times you would like to run the loop:";
        // std::cin >> t;
    }

    void calc()
    {
        std::ofstream out("fourier.dat");
        omega = (2 * (4 * atan(1.0)) / _time_period);
        for (k = 1; k <= _loop_count; k++)
        {
            p = omega * k;
            sum = 0.0;
            for (i = 1; i <= _n; i += 2)
            {
                sum = sum + (sin(i * p)) / i;
            }
            fs = (4 * _a * sum) / (4 * atan(1));
            out << k << "      " << fs << std::endl;
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
        fprintf(gnuplotPipe, "set title 'Fourier Analysis Of Square Waves'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot 'fourier.dat' using 1:2 with lines title 'Resultant'\n");

#ifdef _WIN32
        _pclose(gnuplotPipe);
#else
        pclose(gnuplotPipe);
#endif
    }
};
