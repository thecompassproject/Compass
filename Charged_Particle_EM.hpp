
class field {
private:
    double _q, _m, _vx, _vy, _vz, _Ex, _Ey, _Ez, _Bx, _By, _Bz, _val;
public:
    string input(double q,double m,double vx,double vy,double vz,double Ex,double Ey, double Ez, double Bx, double By, double Bz,double val) {
        /*std::cout << "Enter the charge and mass of the particle:\n";
        std::cin >> q >> m;
        std::cout << "Enter X, Y and Z components of initial velocity:\n";
        std::cin >> vx >> vy >> vz;
        std::cout << "Enter the X, Y and Z components of E field:\n";
        std::cin >> Ex >> Ey >> Ez;
        std::cout << "Enter the X, Y and Z components of B field:\n";
        std::cin >> Bx >> By >> Bz;

        std::cout<<"::For numerical Method ::\n";
        std::cout<<"::    1 for Euler      ::\n";
        std::cout<<"::   2 for Ralston     ::\n";
        std::cout<<":: 3 for Runge-Kutta   ::\n";
        std::cout<<"::Enter the value selected from above::\n";
        std::cin>>val;*/     
        _q = q; 
        _m = m; 
        _vx = vx; _vy = vy; _vz = vz;
        _Ex = Ex; _Ey = Ey; _Ez = Ez; 
        _Bx = Bx; _By = By; _Bz = Bz; 
        _val = val;
        
    }

    double AX(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return _q * (_Ex + (vy1 * _Bz - vz1 * _By)) / _m;
    }

    double AY(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return _q * (_Ey + (vz1 * _Bx - vx1 * _Bz)) / _m;
    }

    double AZ(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
        return _q * (_Ez + (vx1 * _By - vy1 * _Bx)) / _m;
    }

    void solve() {
        std::ofstream out("charge.dat");
        double _n = 3000;
        double _h = 0.0015;
        double _x = 0;
        double _y = 0;
        double _z = 0;

for (double i = 0; i < _n; i++) {
 
 if(_val == 1.0){
 euler3(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      _x, _y, _z, _vx, _vy, _vz, _h);}

else if(_val == 2.0){
 ralston3(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      _x, _y, _z, _vx, _vy, _vz, _h);}

else if(_val == 3.0){
 rk43(std::bind(&field::AX, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AY, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&field::AZ, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      _x, _y, _z, _vx, _vy, _vz, _h);}

else {
std::cout<<"ERROR !!Not Any Method!!\n";
break;
}
            out << _x << "  " << _y << "  " << _z << "\n";
        }
    out.close();

    // Important if building for both Unix and Windows OS
    // Plot the data using gnuplot
        #ifdef _WIN32
            FILE* gnuplotPipe = _popen("gnuplot -persistent", "w");
        #else
            FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
        #endif
        
        if (!gnuplotPipe) {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }

        fprintf(gnuplotPipe, "set title 'Charged Particle Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z Position'\n");
        fprintf(gnuplotPipe, "splot 'charge.dat' using 1:2:3 with lines title 'Trajectory'\n");

    }
};
