#include <iostream>
#include <fstream>
#include <cmath>
#include "rk4C.hpp"
#include "ralstonC.hpp"
class LCR {
private:
    double L, C, R, Q, I,h;

public:
LCR() {
std::cout << "\nEnter inductance (milli H): ";
std::cin >> L;
L *= 1e-3;
        
std::cout << "\nEnter capacitance (micro F): ";
std::cin >> C;
C *= 1e-6;
        
std::cout << "\nEnter resistance: ";
std::cin >> R;

if (pow(R, 2) > (4 * L) / C) {
            std::cout << "\nThe oscillator is over-damped.";
        } 
else if (pow(R, 2) < (4 * L) / C) {
            std::cout << "\nThe oscillator is under-damped.";
        } 
else {
            std::cout << "\nThe oscillator is critically-damped.";
        }
        std::cout << "\n###########################";
    }
    // Wrapper function to match the required header function
double f_wrapper(double A, double B,double Q1, double I1) {
        return -(((Q1 / C) + (R * I1)) / L);
    }

double cha_wrapper(double A, double B,double Q1, double I1) {
        return I1;
    }

void kart() {
   double initialTime, finalTime, I, Q;
   int n;
    std::cout << "\nEnter the number of times you would like to run the loop: ";
    std::cin >> n;
    std::cout << "\nEnter the final time (micro seconds): ";
    std::cin >> finalTime;
    finalTime *= 1e-6;
    std::cout << "\n########################\n";
    double h = (finalTime - initialTime) / n;
    
    std::cout << "\nEnter initial charge (milli C): ";
    std::cin >> Q; Q *= 1e-3;
    
    std::cout << "\nEnter initial current (milli A): ";
    std::cin >> I; I *= 1e-3;
    
    //char name[100];
    //std::cout << "\nEnter the name of the file in which you would like to store the data: ";
    //std::cin >> name;
    //std::cout << "\n############################\n";
    
    std::ofstream out("lcr.dat");
    
    // A and B are dummy variables for the sake of compatibility       
           double A = 0;
           double B = 0;
    
    for (double t = initialTime; t <= finalTime; t += h) {
   // steps calculating is replaced by function call from included header file
calc1(
        std::bind(&LCR::cha_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        std::bind(&LCR::f_wrapper, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),
        A,B,Q,I,h);

        out << t << "  " << I << "  " << Q << "\n";
    }
  }
};

int main() {
    LCR under;
    under.kart();
    return 0;
}
