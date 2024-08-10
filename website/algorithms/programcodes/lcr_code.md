```cpp
//(1) include all the necessary libraries

#include <iostream>     // <iostream> for input(cin) and output(cout) function
#include <fstream>      // <fstream> to input/output data into/from data files
#include <cmath>        // for predefined basic mathematical functions

using namespace std;    // for standard namespace (predefined keywords in c++)

//(2) define a class for simulating the E.M Oscillations of an LCR circuit
class LCR {

private:
	double  L, C, R, Q, I, h, finalTime;
	int n;

public:
	LCR();
	double derivative(double, double);
	void condition();
	void calc();
} object;  // creating an object inside the class

LCR::LCR() {
	/* define a constructor for initialising the initial conditions
		                    like Inductance, Capacitance, Resistance etc. */

	cout << "\nEnter inductance{milli H}:::";
	cin >> L;
	L = L*pow(10,-3);     // for converting milli Henry into Henry

	cout << "\nEnter capacitance{micro F}:::";
	cin >> C;
	C = C*pow(10,-6);     // for converting micro Farad into Farad

	cout << "\nEnter resistance:::";
	cin >> R;

	cout << "\nEnter initial charge:::";
	cin >> Q;
	Q = Q*pow(10,-3);

	cout << "\nEnter initial current:::";
	cin >> I;
	I = I*pow(10,-3);

	cout<<"\nEnter the final time:::";
	cin>>finalTime;

	finalTime = finalTime*pow(10,-6);  // convert the running time into microseconds

	cout<<"\nEnter the no.of times you would like to run the loop:::";
	cin>>n;

	h = (finalTime - 0.0) / n;

}

//(3) define an external function for calculating the first time derivative of current at every timestep
double LCR::derivative(double Q, double I) {
	return -(((Q/C)+(R*I))/L);
}

//(4) using if() and else()	check the nature of LCR Oscillations
void LCR::condition() {

	if ( pow(R, 2) > (4 * L) / C) {
		cout << "\nThe oscillations are over-damped.";   // for over-damped
	}

	else if ( pow(R, 2) < (4 * L) / C) {
		cout << "\nThe oscillations are under-damped.";  // for under-damped
	}

	else {
		cout << "\nThe oscillations are critically-damped."; // for critically-damped
	}
}


//(5) define a calc() function for calculating the Charge and Current in the circuit at every timestep
void LCR::calc() {
	ofstream out("lcr.txt");

//(6) Use RK-4 Method to solve the given ODE at every timestep
	for (double t = 0.0; t <= finalTime; t += h) {

		double l1 = h * I;
		double k1 = h * derivative(Q, I);
		double l2 = h * (I + (k1 / 2));
		double k2 = h * derivative(Q + (l1 / 2), I + (k1 / 2));
		double l3 = h * (I + (k2 / 2));
		double k3 = h * derivative(Q + (l2 / 2), I + (k2 / 2)) ;
		double l4 = h * (I + k3);
		double k4 = h * derivative(Q + l3, I + k3);
		Q = Q + ((l1 + 2 * l2 + 2 * l3 + l4) / 6);
		I = I + ((k1 + 2 * k2 + 2 * k3 + k4) / 6);

		out<<t<<"  "<<I<<"  "<<Q<<"\n";

	}
}


//(7) define a main function to create an instance and call the calc() function
int main() {
// NOTE: the constructor is called automatically for each instance created
	object.condition();
	object.calc();
	return 0;

}




















```
