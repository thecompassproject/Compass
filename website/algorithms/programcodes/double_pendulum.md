```cpp
// (1): Include All Necessary Header files

#include<fstream>       // <fstream> to input/output data into/from data files
//EXERCISE NO 1: Include 'iostream' and 'cmath' header files

using namespace std;    // for standard namespace (predefined keywords in c++)

// (2): Define a Class corresponding to the phase trajectory of a double pendulum

class double_pendulum {

private:
	double g, mass1, mass2, length1, length2, angle1, angle2;

public:
// (3): input or initialise initial parameters like masses, inital angular displacement, etc
	void input();
	double acceleration1(double theta1,double theta2,double omega1,double omega2);
	//EXERCISE NO 2: declare a function named 'acceleration2' that has 'double' return type and takes four parameters: 'theta1', 'theta2', 'omega1', 'omega2', all having 'double' data type

	void calc();
};

void double_pendulum::input() {
	cout << "Enter the masses mass1 and mass2::\n";
	cin >> mass1 >> mass2;

	//EXERCISE NO 3: use the 'cout' command to display the following message: 'Enter the lengths 'length1' and 'length2'::'

	cin >> length1 >> length2;

	cout << "Enter the angles angle1 and angle2::\n";
	//EXERCISE NO 4: use the 'cin' command to ask user to input values that gets assigned to the varaibles 'angle1' and 'angle2'


	angle1 = angle1 * (M_PI / 180);  // convert the angles from degrees to radians
	//EXERCISE NO 5: Convert value of 'angle2' into radians by using 'M_PI/180' factor

	g = 9.8;                         // acceleration due to gravity
}

// (4): Define external functions to calculate the acceleration for Mass 1 and Mass 2
double double_pendulum::acceleration1(double theta1, double theta2, double omega1, double omega2) {
	return (-g*(2*mass1 + mass2)*sin(theta1) - mass2*g*sin(theta1 - 2*theta2) - 2*sin(theta1 - theta2)*mass2*(omega2*omega2*length2 + omega1*omega1*length1*cos(theta1 - theta2))) / (length1 * (2*mass1 + mass2 - mass2*cos(2*theta1 - 2*theta2)));
}

double double_pendulum::acceleration2(double theta1, double theta2, double omega1, double omega2) {
	//EXERCISE NO 6: return the following value: '(2*sin(theta1 - theta2)*(omega1*omega1*length1*(mass1 + mass2) + g*(mass1 + mass2)*cos(theta1) + omega2*omega2*length2*mass2*cos(theta1 - theta2))) / (length2 * (2*mass1 + mass2 - mass2*cos(2*theta1 - 2*theta2)))'


}

// (6): define a calc() function for calculating the trajectory of projectile
void double_pendulum::calc() {
	double angular_velocity1 = 0;
	double angular_velocity2 = 0;
	//EXERCISE NO 7: create a variable 'h' for step size having 'double' data type and assign it a value of '0.0005'

	ofstream out("phase_trajectory.dat");

// (7): calculate the spherical coordinates theta and omega for both masses at every timestep using Ralston method
for(double i = 0; i < 20000; i++) {

		out<< angle1 << "  " << angular_velocity1 << "  " << angle2 << "  " << angular_velocity2 << "\n";

		double k1 = h*acceleration1(angle1, angle2, angular_velocity1, angular_velocity2);
		double f1 = h*acceleration2(angle1, angle2, angular_velocity1, angular_velocity2);

		double k2 = h*acceleration1(angle1, angle2, angular_velocity1 + (3.0/4.0)*k1, angular_velocity2 + (3.0/4.0)*f1);
		double f2 = h*acceleration2(angle1, angle2, angular_velocity1 + (3.0/4.0)*k1, angular_velocity2 + (3.0/4.0)*f1);

		angular_velocity1 = angular_velocity1 + ((1.0/3.0)*k1 + (2.0/3.0)*k2) ;
		//EXERCISE NO 8: Update the value of 'angular_velocity2' by adding to its previous value, the weighted averages of the calculated 'f' slopes. Take help from the value of 'angular_velcoity1' written above.


		angle1 = angle1 + angular_velocity1 * h;
		//EXERCISE NO 9: Update the value of 'angle2' by adding to its previous value, the product of corresponding angular velocity and time step


	}
}

// (8): define a main function for creating an object and calling the required functions
int main() {
	double_pendulum pendulum;
	pendulum.input();
	//EXERCISE NO 10: call 'calc' function of the object 'pendulum'

	return 0;
}

/*ADDITIONAL EXERCISES:
1. Read the program documentation and try solving the problem using other numerical methods and observe which one is more acccurate
2. Observe the effect of changing the value of acceleration due to gravity, 'g'
3. Observe the effect of not converting the angles into radians
4. Play with limits of 'for' loop in the 'calc' function and observe the effects
*/
```
