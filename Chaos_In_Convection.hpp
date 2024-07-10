class chaos{
private:
    double x,y,z,r,bt,sig,val;
public:
chaos(){
std::cout<<"Enter the values of x, y and z::";
std::cin>>x>>y>>z;
 r = 28;  
 bt = 2.667; 
 sig = 10 ;
     std::cout<<"::For numerical Method ::\n";
     std::cout<<"::    1 for Euler      ::\n";
     std::cout<<"::   2 for Ralston     ::\n";
     std::cout<<":: 3 for Runge-Kutta   ::\n";
     std::cout<<"::Enter the value selected from above::\n";
     std::cin>>val;

}

double fx(double A,double B ,double C,double x1,double y1,double z1){
    return sig*(y1-x1);
}

double fy(double A,double B ,double C,double x1,double y1,double z1){
    return (x1*(r-z1)) - y1 ;
}

double fz(double A,double B ,double C,double x1,double y1,double z1){
    return (x1*y1) - (bt*z1) ;
}

void sap(){
double h = 0.01; 
std::ofstream out("chaos.dat");
for(double i=0;i<10000;i++){

double A = 0.0;
double B = 0.0;
double C = 0.0;

if(val == 1.0){
euler3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      A, B, C, x, y, z, h);
}

else if(val == 2.0){
ralston3(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      A, B, C, x, y, z, h);}

else if(val == 3.0){
rk43(std::bind(&chaos::fx, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      std::bind(&chaos::fz, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),
      A, B, C, x, y, z, h);}

else{
std::cout<<"ERROR !!Not any Method!!:: \n";     
break;
}

out<<x<<"  "<<y<<"  "<<z<<"\n";    
    }

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

        fprintf(gnuplotPipe, "set title 'Chaotic Motion'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z Position'\n");
        fprintf(gnuplotPipe, "splot 'chaos.dat' using 1:2:3 with lines title 'Trajectory'\n");
   }
};
