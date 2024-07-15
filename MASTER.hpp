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
#include "Projectile.hpp"          //
#include "Charged_Particle_EM.hpp" //
#include "Double_Pendulum.hpp"     //
#include "LCR_Oscillations.hpp"    //
#include "Drag_Queen.hpp"          //
#include "Chaos_In_Convection.hpp" //
#include "Data_Handling.hpp"       //
#include "Fourier_Sqr_Waves.hpp"   //
#include "Least_Sqr_Fitting.hpp"   //
#include "Quadratic.hpp"           //
#include "Superposition_Waves.hpp" //

class Master
{
private:
  int times, rply, nNn = 12;

public:
  string Slave(double prog_choice, double val, double m, double r, double V0, double th, double c,
               double L, double C, double R, double initialTime, double finalTime, double I, double Q, double n,
               double m1, double m2, double l1, double l2, double o11, double o22, double g,double p,double mu,double x,double v,
               double q,double vx, double vy, double vz, double Ex, double Ey, double Ez, double Bx, double By, double Bz,
               double y , double z )
  {
    if (prog_choice == 1.0)
    {
      proj p;
      p.input(val, m, r, V0, th, c);
      return p.ND();
    }
    else if (prog_choice == 2.0)
    {
      LCR under;
      string message = under.input(val, L, C, R);
      under.kart(initialTime, finalTime, I, Q, n);
      return message;
    }
    else if (prog_choice == 3.0)
    {
      double_pendulum d;
      d.input(m1, m2, l1, l2, o11, o22, g, val);
      d.yo();
    }
    else if (prog_choice == 4.0)
    {
      field f;
      f.input(q,m,vx,vy,vz,Ex,Ey,Ez,Bx,By,Bz,val);
      f.solve();
    }
    else if (prog_choice == 5.0)
    {
      peace jude;
      jude.saman();
      jude.sejal();
      jude.sage();
      jude.raavi();
      jude.romi();
      jude.dualipa();
    }
    else if (prog_choice == 6.0)
    {
      fourier series;
      series.input();
      series.calc();
    }
    else if (prog_choice == 7.0)
    {
      Fitit fi;
      fi.inp();
      fi.calc();
      fi.printit();
    } // this block is for adding more programs
    else if (prog_choice == 8.0)
    {
      Quad q;
      q.coeff();
      q.roots();
    }
    else if (prog_choice == 9.0)
    {
      kick stand;
      stand.up();
      stand.at_ease();
      stand.still();
    }
    else if (prog_choice == 10.0)
    {
      chaos A;
      A.input(x,y,z,val);
      A.sap();
    }
    else if (prog_choice == 11.0)
    {
      drag queen;
      queen.input(r,p,g,m,mu,c,x,v,val) ;
      string message = queen.b() ;
      return message;
    }
    else
    {
      return "";
    }
  }
};
