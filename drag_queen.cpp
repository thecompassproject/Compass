#include<iostream>
#include<fstream>
#include<cmath>
#include "Euler.hpp"
#include "rk4.hpp"
class drag{
private:
    float r,p, g, m, c,mu;
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
        euler(std::bind(&drag::yoko,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),x,v,A,-h);
        euler(std::bind(&drag::ono,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),v,a,A,h);
        
        if(x<0){
            break;
      }
    }
  }
}queen;

int main(){
queen.b();
return 0;
}







