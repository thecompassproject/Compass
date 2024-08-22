```cpp
//(1) include all the necessary libraries


#include <fstream>  // <fstream> to input/output data into/from data files
//EXERCISE NO 1: Include 'iostream' and 'cmath' header files



using namespace std; // for standard namespace (predefined keywords in c++)

//(2) define a class for determining the dynamics of a falling spherical body through a medium
class falling_body
{

private:
    float r, density, g, mass, drag_coeff, mu, vol, den, x, v, h, newton_drag, stokes_drag, buoyant_drag;

public:
    falling_body();
    //EXERCISE NO 2: declare a function named 'retard' that has 'float' return type and takes one parameter 'velo'

    void calc();
};

falling_body::falling_body()
{
    /* define a constructor for initialising the initial conditions
                            like radius of spherical body, drag coeff. etc */

    cout << "\nEnter the radius of the sphere [meter]:::";
    cin >> r;
    cout << "\nEnter Mass of the sphere [kg]:::";
    cin >> mass;
    cout << "\nEnter the density of medium [kg/m^3]:::";
    cin >> density;
    //EXERCISE NO 3: use the 'cout' command to display the following message: '\nEnter Acceleration Due to Gravity [m/sec^2]:::'

    cin >> g;
    cout << "\nEnter the Coefficient of drag:::";
    //EXERCISE NO 4: use the 'cin' command to ask user to input values that gets assigned to the varaibles 'drag_coeff'

    cout << "\nEnter the Coefficient of viscosity:::";
    cin >> mu;
    cout << "\nEnter the initial value of Height [meter]:::";
    cin >> x;
    cout << "\nEnter the initial value of Velocity [m/sec]:::";
    cin >> v;
    h = 0.015;
}

//(3) define an external function for calculating the retardation due to drag at each timestep
float falling_body::retard(float velo)
{
    newton_drag = (((density*4*atan(1)*drag_coeff*r*r)/(2*mass))*velo*velo);    // term for Newtonian drag

	stokes_drag = ((6*4*atan(1)*mu*r*velo)/mass);     // term for Stokes' drag

    //EXERCISE NO 5: assign value '((4*density*r*r*r*4*atan(1)*g)/(3*mass))' to variable 'buoyant_drag'


	return g - newton_drag - stokes_drag - buoyant_drag ;

}

//(4) define a calc() function for calculating the position, velocity, acceleration at each timestep
void falling_body::calc()
{
    for (double num = 0; num < 1; num++)
    {

        vol = (4.0 / 3.0) * M_PI * r * r * r;
        //EXERCISE NO 6: define body density variable 'den' and assign it the value of ratio of variables 'mass' and 'vol'


        if (den <= density)
        {
            cout << "HEY, The values Entered Aren't Practical. Density of the body < Density of  medium. The body will float!\n"; // to terminate the loop if the density of the body < density of  medium
            break;
        }

        std::ofstream out("drag2.dat");
        for (float t = 0.0; t > -1; t += h)
        {

            out << t << "  " << x << "  " << v << "  " << retard(v) << "\n";

            //(5) using euler mathod to solve for height and velocity
            x = x - h * v;
            //EXERCISE NO 7: Update the value of 'v' by adding to its previous value, the product of time step 'h' and result of retard function 'retard(v)'


            if (x < 0)
            {
                break; // to terminate the loop when the body attains 0 height
            }
        }
    }
}

//(6) define a main function to create an instance and call the calc() function
int main()
{
    falling_body object;
    // NOTE: the constructor is called automatically for each instance created
    object.calc();
    return 0;
}
/*
1. Read the program documentation and try solving the problem using other numerical methods and observe which one is more acccurate
2. Observe the effect of removing one or more drag forces
4. Play with limits of 'for' loop in the 'calc' function and observe the effects
*/
```
