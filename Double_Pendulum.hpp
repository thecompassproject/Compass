class double_pendulum {
private:
    double g, m1, m2, l1, l2, o11, o22,val;

public:
    double_pendulum() {
        std::cout << "Enter the masses m1 and m2 (in kg):\n";
        std::cin >> m1 >> m2;
        std::cout << "Enter the lengths l1 and l2 (in meters):\n";
        std::cin >> l1 >> l2;
        std::cout << "Enter the angles o1 and o2 (in degrees):\n";
        std::cin >> o11 >> o22;
        o11 = o11 * (M_PI / 180);
        o22 = o22 * (M_PI / 180);
        std::cout<<"Enter the Acceleration due to gravity:\n";
        std::cin>>g
        std::cout<<"::For numerical Method ::\n";
        std::cout<<"::    1 for Euler      ::\n";
        std::cout<<"::   2 for Ralston     ::\n";
        std::cout<<":: 3 for Runge-Kutta   ::\n";
        std::cout<<"::Enter the value selected from above::\n";
        std::cin>>val;
        
    }
double ac1(double th1, double th2, double og1, double og2) {
        return (-g*(2*m1 + m2)*sin(th1) - m2*g*sin(th1 - 2*th2) - 2*sin(th1 - th2)*m2*(og2*og2*l2 + og1*og1*l1*cos(th1 - th2))) / (l1 * (2*m1 + m2 - m2*cos(2*th1 - 2*th2)));
    }
double ac2(double th1, double th2, double og1, double og2) {
        return (2*sin(th1 - th2)*(og1*og1*l1*(m1 + m2) + g*(m1 + m2)*cos(th1) + og2*og2*l2*m2*cos(th1 - th2))) / (l2 * (2*m1 + m2 - m2*cos(2*th1 - 2*th2)));
    }
void yo() {
        double meg11 = 0;
        double meg22 = 0;
        double h = 0.0005;
        std::ofstream outfl("tra.dat");
        for (double i = 0 ; i < 20000 ; i++) {
            double x11 = l1 * sin(o11);
            double y11 = -l1 * cos(o11);
            double x22 = x11 + (l2 * sin(o22));
            double y22 = y11 - (l2 * cos(o22));
            outfl << x11 << "  " << y11 << "  " << x22 << "  " << y22 << "\n";
if(val == 1.0){
calc4(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        o11, o22, meg11, meg22, h);
}
            

else if(val == 2.0){
calc(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        o11, o22, meg11, meg22, h);
}            

else if(val == 3.0){
calc1(std::bind(&double_pendulum::ac1, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&double_pendulum::ac2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        o11, o22, meg11, meg22, h);
}
        
else{
std::cout<<"ERROR !!Not any type!!\n";     
break;     
}             
        }
     outfl.close();

        // Plot the data using gnuplot
        FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
        if (!gnuplotPipe) {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }
        fprintf(gnuplotPipe, "set size ratio -1 \n");
        fprintf(gnuplotPipe, "set title 'Double Pendulum Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position'\n");
        fprintf(gnuplotPipe, "plot 'tra.dat' using 1:2 with lines title 'Mass^1'\n");
        fprintf(gnuplotPipe, "replot 'tra.dat' using 3:4 with lines title 'Mass^2'\n");
    }
};
