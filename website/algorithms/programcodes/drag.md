```cpp
//(1) include all the necessary libraries

#include <iostream> // <iostream> for input(cin) and output(cout) function
#include <fstream>  // <fstream> to input/output data into/from data files
#include <cmath>    // for predefined basic mathematical functions

    using namespace std; // for standard namespace (predefined keywords in c++)

//(2) define a class for determining the dynamics of a falling spherical body through a medium
class falling_body
{

private:
    float r, density, g, mass, drag_coeff, mu, vol, den, x, v, h;

public:
    falling_body();
    float retard(float);
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
    cout << "\nEnter Acceleration Due to Gravity [m/sec^2]:::";
    cin >> g;
    cout << "\nEnter the Coefficient of drag:::";
    cin >> drag_coeff;
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

    // term corresponding to Newtonian drag                    // term for Stoke's drag         // term for Buoyancy drag

    return g - (((density * 4 * atan(1) * drag_coeff * r * r) / (2 * mass)) * velo * velo) - ((6 * 4 * atan(1) * mu * r * velo) / mass) - ((4 * density * r * r * r * 4 * atan(1) * g) / (3 * mass));
}

//(4) define a calc() function for calculating the position, velocity, acceleration at each timestep
void falling_body::calc()
{
    for (double num = 0; num < 1; num++)
    {

        vol = (4.0 / 3.0) * M_PI * r * r * r;
        den = mass / vol;

        if (den <= density)
        {
            cout << "HEY, The values Entered Aren't Practical:::\n"; // to terminate the loop if the density of the body < medium
            break;
        }

        std::ofstream out("drag2.dat");
        for (float t = 0.0; t > -1; t += h)
        {

            out << t << "  " << x << "  " << v << "  " << retard(v) << "\n";

            //(5) using euler mathod to solve for height and velocity
            x = x - h * v;
            v = v + h * retard(v);

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
```
