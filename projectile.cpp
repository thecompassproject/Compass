#include<iostream>
#include<fstream>
#include<cmath>
#include "Fn.hpp"
#include "Euler.hpp"
#include "ralston.hpp"
#include "rk4.hpp"
class proj{
private:
double  V0,th,c,m,g,p,r,q,a,ax,ay;
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
       q = 0; break; }
    else{
        q = 1; }
    std::cout<<"The mass of the projectile::";
    std::cin>>m;
     p = 1.22;
     r = 0.2; 
    a = 0.0;
    }
 }
double S(double a , double b, double c){
    return c ;
}
double A(double V){
    return g - (((p*4*atan(1)*c*r*r)/(2*m))*V*V) ;
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
    ax = q*(A(Vx) - g);
    ay = A(Vy);
    fn(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),Vx,ax,a,h);
    fn(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),Vy,ay,a,h);
    fn(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),X0,Vx,a,h);
    fn(std::bind(&proj::S, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),Y0,Vy,a,h);
    if(Y0<0){
       break ;
     }
    }    
  }
}s;
int main(){
s.ND();
return 0;
}











