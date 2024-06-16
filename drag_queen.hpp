class drag{
private:
    float r,p, g, m, c,mu,val;
    double A,B;
public:
drag(){
    std::cout<< "Make sure the parameters should be in equivalent units\n";
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
    std::cin>>val;  
}

float ono(double A,double v1,double B) {
return g - (((p*4*atan(1)*c*r*r)/(2*m))*v1*v1)-((6*4*atan(1)*mu*r*v1)/m)-((4*p*r*r*r*4*atan(1)*g)/(3*m)) ;
    }

float yoko(double A, double x1 , double B1){
    return B1 ;
}

void b() { 
    double in, x, v,a;
    float h = 0.15 ; 
    A = 0; B = 0;
    std::cout<< "\nEnter the initial value of Height:::";
    std::cin>>x;
    std::cout<< "\nEnter the initial value of Velocity:::";
    std::cin>>v;  
    std::ofstream out("drag1.dat");
    for (float t = 0.0; t > -1; t += h){
        a = ono(A,v,B);
        out<<t<<"  "<<x<<"  "<<v<<"  "<<a<<"\n";
        if(val == 1.0){
        eulersA(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),x,v,A,-h);
        eulersA(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),v,a,A,h);
        }
        
       else if(val == 2.0){
        ralsA(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),x,v,A,-h);
        ralsA(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),v,a,A,h);
        }
        
       else if(val == 3.0){
        rk4A(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),x,v,A,-h);
        rk4A(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),v,a,A,h);
        }
        
        else{
           std::cout<<"ERROR !!Not any Method!! \n";  
           break;
          }
        
        if(x<0){
            break;
      }
    }
  }
};