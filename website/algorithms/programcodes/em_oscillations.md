```cpp
//(1) include all the necessary libraries

#include<iostream>     // <iostream> for input(cin) and output(cout) function
#include<fstream>      // <fstream> to input/output data into/from data files
#include<cmath>        // for predefined basic mathematical functions

using namespace std;   // for standard namespace (predefined keywords in c++)

//(2) define a class for simulating the motion of a charged particle in E.M field
class EM_field {

private:
	double q, m, vx, vy, vz, Ex, Ey, Ez, Bx, By, Bz, h;

public:
	EM_field();
	double AX(double, double, double, double, double, double);
	double AY(double, double, double, double, double, double);
	double AZ(double, double, double, double, double, double);
	void calc();
};

EM_field::EM_field() {
	/* define a constructor for initialising the initial conditions
		                    like components of Velocity, Electric field, Magnetic field etc. */

	cout << "Enter the charge and mass of the particle:\n";
	cin >> q >> m;
	cout << "Enter X, Y and Z components of initial velocity:\n";
	cin >> vx >> vy >> vz;
	cout << "Enter the X, Y and Z components of E field:\n";
	cin >> Ex >> Ey >> Ez;
	cout << "Enter the X, Y and Z components of B field:\n";
	cin >> Bx >> By >> Bz;

}

//(3) define external functions for calculating the components of acceleration due to E.M Field
double EM_field::AX(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
	return q * (Ex + (vy1 * Bz - vz1 * By)) / m;            //acceleration in X direction
}

double EM_field::AY(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
	return q * (Ey + (vz1 * Bx - vx1 * Bz)) / m;            //acceleration in Y direction
}

double EM_field::AZ(double x1, double y1, double z1, double vx1, double vy1, double vz1) {
	return q * (Ez + (vx1 * By - vy1 * Bx)) / m;            //acceleration in Z direction
}

//(4) define a calc() function for calculating the position, velocity, acceleration at each timestep
void EM_field::calc() {
	ofstream out("charge.dat");
	double n = 3000;
	h = 0.0015;  // define a step size
	double x = 0;
	double y = 0;
	double z = 0;

	for (double i = 0; i < n; i++) {
//(5) using euler mathod to solve for acceleration, velocity, position at each timestep
		double dvx = h * AX(x, y, z, vx, vy, vz);
		double dvy = h * AY(x, y, z, vx, vy, vz);
		double dvz = h * AZ(x, y, z, vx, vy, vz);


		x += h * vx;
		y += h * vy;
		z += h * vz;

		vx += dvx;
		vy += dvy;
		vz += dvz;

		out << x << "  " << y << "  " << z << "\n";
	}
}


//(6) define a main function to create an instance and call the calc() function
int main() {
	EM_field c1;
// NOTE: the constructor is called automatically for each instance created
	c1.calc();
	return 0;
}
```
