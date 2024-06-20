#include <iostream>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include "ralston.hpp"
#include "rk4.hpp"
#include "Euler.hpp"
#include "ralstonC.hpp"
#include "rk4C.hpp"
#include "EulerC.hpp"
#include "ralstonC3.hpp"
#include "rk4C3.hpp"
#include "EulerC3.hpp"
#include "proj.hpp"             //
#include "field.hpp"           //
#include "double_pendulum.hpp"//
#include "LCR.hpp"           //
#include "drag_queen.hpp"   //
#include "chaos.hpp"       //
#include "peace.hpp"      //
#include "fourier.hpp"   //
#include "Fitit.hpp"    //
#include "Quad.hpp"    //
#include "kick.hpp"   //
class Master{
private:   
int times,rply,nNn = 12;
double choice;

public:
void Slave(){
for(times = 0; times<nNn; times ++){
std::cout<<"Which problem would you like to run::\n";
std::cout<<" 1.  -  for   -   projectile\n";
std::cout<<" 2.  -  for   -   motion-of-charged-particle-in-EM-field\n";
std::cout<<" 3.  -  for   -   data-handling\n";
std::cout<<" 4.  -  for   -   fourier-analysis\n";
std::cout<<" 5.  -  for   -   least-square-fitting\n";
std::cout<<" 6.  -  for   -   quadratic-equation\n";
std::cout<<" 7.  -  for   -   superposition-of-waves\n";
std::cout<<" 8.  -  for   -   double-pendulum\n";
std::cout<<" 9.  -  for   -   LCR-circuit\n";
std::cout<<"10.  -  for   -   chaos-lorentz-system\n";
std::cout<<"11.  -  for   -   motion-of-a-falling-spherical-body\n";
//std::cout<<"n    for         name\n";
//std::cout<<"n    for         name\n";
//std::cout<<"n    for         name\n";
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
std::cout<<"Enter the S.No of choice\n";
std::cin>>choice;
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
////////////////////////////////////////
if(choice == 1.0){
     proj p;
     p.ND();
}     
else if(choice == 2.0){                 
     field f;
     f.solve();
}
else if(choice == 3.0){                
     peace jude;
    jude.saman();
    jude.sejal();
    jude.sage();
    jude.raavi();
    jude.romi();
    jude.dualipa();
}
else if(choice == 4.0){                 
fourier series;
  series.input();
  series.calc();     
}
else if(choice == 5.0){                 
Fitit fi;
  fi.inp();
  fi.calc();
  fi.printit();
}                                                                         //this block is for adding more programs
else if(choice == 6.0){                 
Quad q;
  q.coeff ();
  q.roots ();
}
else if(choice == 7.0){                 
kick stand ;
    stand.up();
    stand.at_ease();
    stand.still();
}
else if(choice == 8.0){                 
double_pendulum d;
    d.yo();
}
else if(choice == 9.0){                 
 LCR under;
    under.kart();
}
else if(choice == 10.0){                 
 chaos A;
    A.sap();
}
else if(choice == 11.0){                 
 drag queen;
queen.b();
}
///////////////////////////////////////
else{
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
std::cout<<"NOT ANY TYPE ERROR !!!!!\n";
break;
}     
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
std::cout<<"Would like to run some other problem\n";
std::cout<<"yes(1) or no(0), Enter the number corresponding to yes or no \n";
std::cin>>rply;
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
if(rply == 0){
break;     
     }
std::cout<<"Turns left are :: "<< nNn - times - 1 <<"\n";
std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}      
}     
};