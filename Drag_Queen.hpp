class drag{
private:
    double _r,_p, _g, _m, _c,_mu,_val,_x,_v,vol,den;
    double A,B;
public:
string input(double r,double p , double g, double m, double mu , double c , double x , double v,double val){
    /*std::cout<< "Make sure the parameters should be in equivalent units\n";
    std::cout<< "\nEnter the radius of the sphere:::";
    std::cin>>r;
    std::cout<< "\nEnter the density of medium, Acceleration Due to Gravity, Mass of the sphere (respectively):::\n";
    std::cin>>p>>g>>m;   
    std::cout<<"\nEnter the Coefficient of viscosity:::";
    std::cin>>mu;
    std::cout<<"\nEnter the Coefficient of drag:::";
    std::cin>>c;
    std::cout<<"::For numerical Method ::\n";
    std::cout<<"::    1 for Euler      ::\n";
    std::cout<<"::   2 for Ralston     ::\n";
    std::cout<<":: 3 for Runge-Kutta   ::\n";
    std::cout<<"::Enter the value selected from above::\n";
    std::cin>>val;*/  
_r = r; _p = p; 
_g = g; _m = m; 
_c = c; _mu = mu; 
_val = val;
_x = x;
_v = v;
    
}

float ono(double A,double v1,double B) {
return _g - (((_p*4*atan(1)*_c*_r*_r)/(2*_m))*v1*v1)-((6*4*atan(1)*_mu*_r*v1)/_m)-((4*_p*_r*_r*_r*4*atan(1)*_g)/(3*_m)) ;
    }

float yoko(double A, double x1 , double B1){
    return B1 ;
}

void b() { 
    for(double at = 0.0 ; at < 1 ; at ++){
    double _a;
    double h = 0.15 ; 
    A = 0; B = 0;
    /*std::cout<< "\nEnter the initial value of Height:::";
    std::cin>>x;
    std::cout<< "\nEnter the initial value of Velocity:::";
    std::cin>>v;*/  
    vol = (4.0/3.0)*M_PI*_r*_r*_r;
    den = _m/vol;
    if(den <= _p){
        //std::cout<<"HEY, The values Entered Are'nt Practical:::\n";
        return "Message: HEY, The values Entered Are'nt Practical";
        break;
    }
    std::ofstream out("drag.dat");
    for (double t = 0.0; t > -1; t += h){
        _a = ono(A,_v,B);
        out<<t<<"  "<<_x<<"  "<<_v<<"  "<<_a<<"\n";
        if(_val == 1.0){
        eulersA(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_x,_v,A,-h);
        eulersA(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_v,_a,A,h);
        }
        
       else if(_val == 2.0){
        ralsA(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_x,_v,A,-h);
        ralsA(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_v,_a,A,h);
        }
        
       else if(_val == 3.0){
        rk4A(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_x,_v,A,-h);
        rk4A(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),_v,_a,A,h);
        }
        
        else{
           //std::cout<<"ERROR !!Not any Method!! \n";  
           break;
          }
        
        if(_x<0){
            break;
      }
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
        fprintf(gnuplotPipe, "set title 'Motion Of Spherical Body'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Height/Velocity/Acceleration'\n");
        fprintf(gnuplotPipe, "plot 'drag.dat' using 1:2 with lines title 'Height'\n");
        fprintf(gnuplotPipe, "replot 'drag.dat' using 1:3 with lines title 'Velocity'\n");
        fprintf(gnuplotPipe, "replot 'drag.dat' using 1:4 with lines title 'Acceleration'\n");
  }
}
};
