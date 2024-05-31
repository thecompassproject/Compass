#include<iostream>
#include<fstream>
#include<cmath>
#include "rk4.hpp"
#include "ralston.hpp"
class field{
    private:
    double q,m,vx,vy,vz,Ex,Ey,Ez,Bx,By,Bz,h;
    public:
 field(){
 std::cout<<"enter the charge and mass of the particle::\n";
 std::cin>>q>>m;
 std::cout<<"enter X, Y and Z components of initial velocity::\n";
 std::cin>>vx>>vy>>vz;
 std::cout<<"enter the X,Y and Z components of E field::\n";
 std::cin>>Ex>>Ey>>Ez;
 std::cout<<"enter the X,Y and Z components of M field::\n";
 std::cin>>Bx>>By>>Bz;
}
double cp(double A,double F, double FF){
    return FF*h ;
}
void solve(){
std::ofstream out("sam.dat");
double n = 300000 ; 
 h = 0.0015 ; 
double x = 0 ; 
double y = 0 ; 
double z = 0 ;
double A = 0 ;
for( double i=0;i<n;i++){
double Fx = q*(Ex + (vy*Bz - vz*By));    
double Fy = q*(Ey + (vz*Bx - vx*Bz));
double Fz = q*(Ez + (vx*By - vy*Bx));    
double ax = Fx/m ; 
double ay = Fy/m ; 
double az = Fz/m ;

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),vx,ax,A,h);

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),vy,ay,A,h);

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),vz,az,A,h);

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),x,vx,A,h);

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),y,vy,A,h);

calc2(std::bind(&field::cp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),z,vz,A,h);

out<<x<<"  "<<y<<"  "<<z<<"  "<<"\n";    
    }
  }    
}c1;
int main(){
c1.solve();
return 0;    
}
