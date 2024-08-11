```cpp
//(1) include all the necessary libraries

#include<iostream>     // <iostream> for input(cin) and output(cout) function
//EXERCISE NO 1: Include 'cmath' and 'fstream' header files

using namespace std;   // for standard namespace (predefined keywords in c++)

//(2) define a class for simulating the motion of a charged particle in E.M field
class EM_field {

private:
	double q, m, vx, vy, vz, Ex, Ey, Ez, Bx, By, Bz, h;

public:
	EM_field();
	double AX(double vy1, double vz1);
	//EXERCISE NO 2: declare function named 'AY' having 'double' return type and admitting parameters 'vx1' and 'vz1' both having 'double' data type

	//EXERCISE NO 3: declare function named 'AZ' having 'double' return type and admitting parameters 'vx1' and 'vy1' both having 'double' data type

	void calc();
};

EM_field::EM_field() {
	/* define a constructor for initialising the initial conditions
		                    like components of Velocity, Electric field, Magnetic field etc. */

	cout << "Enter the charge and mass of the particle:\n";
	cin >> q >> m;
	//EXERCISE NO 4: use the 'cout' command to display the following message: 'Enter X, Y and Z components of initial velocity:\n'
	cin >> vx >> vy >> vz;
	cout << "Enter the X, Y and Z components of E field:\n";
	//EXERCISE NO 5: use the 'cin' command to ask user to input values that gets assigned to the varaibles 'Ex', 'Ey' and 'Ez'

	cout << "Enter the X, Y and Z components of B field:\n";
	cin >> Bx >> By >> Bz;

}

//(3) define external functions for calculating the components of acceleration due to E.M Field
double EM_field::AX(double vy1, double vz1) {
	return q * (Ex + (vy1 * Bz - vz1 * By)) / m;            //acceleration in X direction
}

double EM_field::AY(double vx1, double vz1) {
	//EXERCISE NO 6: return the following value: 'q * (Ey + (vz1 * Bx - vx1 * Bz)) / m'
}

////EXERCISE NO 7: Use the scope resolution operator '::' to start definition of 'AZ' function of the class 'EM_field'. Wrap the 'return' statement writtne below in {}. Take help from the two functions defined above.

	return q * (Ez + (vx1 * By - vy1 * Bx)) / m;            //acceleration in Z direction


//(4) define a calc() function for calculating the position, velocity, acceleration at each timestep
void EM_field::calc() {
	ofstream out("charge.dat");
	double n = 3000;
	h = 0.0015;  // define a step size
	//EXERCISE NO 8: create intial condition variables 'x', 'y' and 'z' all having 'double' data type and assign them all the value '0'




	for (double i = 0; i < n; i++) {
//(5) using euler mathod to solve for acceleration, velocity, position at each timestep
		double dvx = h * AX(vy, vz);
		double dvy = h * AY(vx, vz);
		//EXERCISE NO 9: create a variable 'dvz' of 'double' data type and assign it the value of product of 'h' and the function 'AZ(vx,vy)'


        x += h * vx;
		y += h * vy;
		//EXERCISE NO 10: update the value of variable 'z' by adding to its previous value, the product of 'h' and 'vz'


		vx += dvx;
		//EXERCISE NO 11: update the value of variable 'vy' by adding 'dvy' to its previous value

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

/*ADDITIONAL EXERCISES:
1. Read the program documentation and try solving the problem using other numerical methods and observe which one is more acccurate
2. Observe what is the effect of changing the value of 'n' and 'n'
3. Play with limits of 'for' loop in the 'calc' function and observe the effects
*/

```
