#include<iostream>
#include<fstream>
#include<cmath>
#include "Fn.hpp"
#include "Euler.hpp"
#include "rk4.hpp"
class chao{
private:
    double x,y,z,r,bt,sig;
public:
chao(){
std::cout<<"Enter the values of x, y and z::";
std::cin>>x>>y>>z;
 r = 28;  
 bt = 2.667; 
 sig = 10 ;
    }
double fx(double A,double x1 ,double B){
    return sig*(y-x1);
}
double fy(double A,double y1 ,double B){
    return (x*(r-z)) - y1 ;
}
double fz(double A,double z1 ,double B){
    return (x*y) - (bt*z1) ;
}
void sap(){
double h = 0.01; 

std::ofstream out("chaos.dat");
for(double i=0;i<10000;i++){
double A = 0.0;
double B = 0.0;
 
calc2(std::bind(&chao::fx,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),x,B,A,h);
calc2(std::bind(&chao::fy,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),y,B,A,h);
calc2(std::bind(&chao::fz,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3),z,B,A,h);

out<<x<<" "<<y<<" "<<z<<"\n";    
    }
   }
}A;

int main(){
    A.sap();
    return 0;
}




