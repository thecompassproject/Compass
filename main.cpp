#include <pybind11/pybind11.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "master.hpp"
using namespace std;

string mainserver(double prog_choice, double method_choice, double m, double r, double V0, double th, double c,
                  double L, double C, double R, double initialTime, double finalTime, double I, double Q, double n,
                  double m1, double m2, double l1, double l2, double o11, double o22, double g,
                  double p, double mu, double x, double v,
                  double q, double vx, double vy, double vz, double Ex, double Ey, double Ez, double Bx, double By, double Bz,
                  double sigma, double rho, double beta, double y, double z, double h,
                  double time_period, double a, double loop_count,
                  double b)
{
    Master Free;
    string response = Free.Slave(prog_choice, method_choice, m, r, V0, th, c,
                                 L, C, R, initialTime, finalTime, I, Q, n,
                                 m1, m2, l1, l2, o11, o22, g,
                                 p, mu, x, v,
                                 q, vx, vy, vz, Ex, Ey, Ez, Bx, By, Bz,
                                 y, z, sigma, rho, beta, h,
                                 time_period, a, loop_count,
                                 b);
    return response;
}

PYBIND11_MODULE(cpp_function, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("run", &mainserver, "The main entry point for access to C++ code from Python");
}
