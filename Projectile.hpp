class proj{
private:
double  V0,th,c,m,g,p,r,ax,ay,val;
public:
proj(){
    std::cout<<"Enter the initial velocity::";
    std::cin>>V0;
    std::cout<<"The angle at which the projectile is ejected::";
    std::cin>>th;
    
    th = (M_PI/180.0)*th; g = -9.8; m=1;
    
    std::cout<<"The drag coefficient for the body is::";
    std::cin>>c;
    
    for(double i =0 ;i<1;i++){
    if(c==0){
       m = 1;
       break; }
    std::cout<<"The mass of the projectile::";
    std::cin>>m;
     p = 1.22;
    std::cout<<"Enter the radius of spherical projectile::\n";
    std::cin>>r;    
     //r = 0.2; 
    }
 
        std::cout<<"::For numerical Method ::\n";
        std::cout<<"::    1 for Euler      ::\n";
        std::cout<<"::   2 for Ralston     ::\n";
        std::cout<<":: 3 for Runge-Kutta   ::\n";
        std::cout<<"::Enter the value selected from above::\n";
        std::cin>>val;     

}

double S(double X1,double Y1,double Vx1,double Vy1){
      return  -(((p*4*atan(1)*c*r*r)/(2*m))*Vx1*Vx1) ;
}

double A(double X11,double Y11,double Vx11,double Vy11){
    return  g - (((p*4*atan(1)*c*r*r)/(2*m))*Vy11*Vy11) ;
}

void ND(){
    std::ofstream out("sam.dat");
    double X0 = 0.0;
    double Y0 = 0.0;
    double Vx = V0 * cos(th) ;
    double Vy = V0 * sin(th) ;
    double mh = pow((V0*sin(th)),2)/(2*9.8);
    std::cout<<"Max height achieved without drag is "<<mh<<"\n";
    double h = 0.001; 
for(double t=0 ;t<100 ;t+=h){
    out<<X0<<"  "<<Y0<<"\n"; 
  
    
    if(val == 1.0){
   calc4(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&proj::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        X0, Y0, Vx, Vy, h);
    }
    
    else if(val == 2.0){
     calc(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&proj::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        X0, Y0, Vx, Vy, h);}
    
    else if(val == 3.0){
     calc1(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&proj::A, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        X0, Y0, Vx, Vy, h);}
    
    else{
     std::cout<<"ERROR !!Not Any Method!!\n";    
    break;
   }
    
    if(Y0<0){
       break ;
     }
    }    
   out.close();

        // Plot the data using gnuplot
        FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
        if (!gnuplotPipe) {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }

        fprintf(gnuplotPipe, "set title 'Projectile Trajectory'\n");
        fprintf(gnuplotPipe, "set xlabel 'X Position (m)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y Position (m)'\n");
        fprintf(gnuplotPipe, "plot 'sam.dat' using 1:2 with lines title 'Trajectory'\n");

     
  }
};
