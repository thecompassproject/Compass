```cpp
//(1) include all the necessary libraries

#include <cmath>        // for predefined basic mathematical functions
//EXERCISE NO 1: Include 'iostream' and 'fstream' header files

using namespace std;    // for standard namespace (predefined keywords in c++)

//(2) define a class for simulating the E.M Oscillations of an LCR circuit
class LCR {

private:
	double  L, C, R, Q, I, h, finalTime;
	//EXERCISE NO 2: Create a varible 'n' having data type 'int'

public:
	LCR();
	double derivative(double Q, double I);
	//EXERCISE NO 3: declare functions named 'condition' and 'calc' both having 'void' return type and not admitting any parameters


};

LCR::LCR() {
	/* define a constructor for initialising the initial conditions
		                    like Inductance, Capacitance, Resistance etc. */

	cout << "\nEnter inductance{milli H}:::";
	cin >> L;
	L = L*pow(10,-3);     // for converting milli Henry into Henry

	cout << "\nEnter capacitance{micro F}:::";
	cin >> C;
	//EXERCISE NO 4: Convert value of 'C' into Farads by using 'pow' function

	cout << "\nEnter resistance:::";
	cin >> R;

	cout << "\nEnter initial charge:::";
	cin >> Q;
	Q = Q*pow(10,-3);    // for converting milli coulomb to coulomb

	cout << "\nEnter initial current:::";
	cin >> I;
	//EXERCISE NO 4: Convert value of 'I' into Coulombs by using 'pow' function

	cout<<"\nEnter the final time:::";
	cin>>finalTime;

	finalTime = finalTime*pow(10,-6);  // convert the running time into microseconds

	cout<<"\nEnter the no.of times you would like to run the loop:::";
	cin>>n;

	h = (finalTime - 0.0) / n;

}

//(3) define an external function for calculating the first time derivative of current at every timestep
double LCR::derivative(double Q, double I) {
	//EXERCISE 5: return the following value: '-(((Q/C)+(R*I))/L)'

}

//(4) using if() and else()	check the nature of LCR Oscillations
void LCR::condition() {

	if (pow(R, 2) > (4 * L) / C) {
		cout << "\nThe oscillations are over-damped.";   // for over-damped
	}

	//EXERCISE NO 6: write the condition for the under-damped case using 'else if' keyword and using '<' sign. Wrap the 'cout' command written below in this condition usign {}

		cout << "\nThe oscillations are under-damped.";  // for under-damped

	else {
	//EXERCCISE NO 7: Use 'cout' command to display the following message: 'The oscillations are critically-damped.'
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
		//EXERCISE NO 8: Update the value of 'I' by adding to its previous value, the average of the calculated 'k' slopes. Take help from the value of 'Q' written above.

		out<<t<<"  "<<I<<"  "<<Q<<"\n";

	}
}


//(7) define a main function to create an instance and call the calc() function
int main() {
// NOTE: the constructor is called automatically for each instance created
	LCR circuit;
	circuit.condition();
	//EXERCISE NO 9: call 'calc' function of the object 'circuit'

	return 0;

}

/*ADDITIONAL EXERCISES:
1. Read the program documentation and try solving the problem using other numerical methods and observe which one is more acccurate
2. Observe what is the effect of not converting the user input values to appropriate units


```
