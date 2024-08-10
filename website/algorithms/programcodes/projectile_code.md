```cpp
// (1): Include All Necessary Header files

#include<iostream>                     // <iostream> for input(cin) and output(cout) function
//EXERCISE NO 1: Include 'fstream' and 'cmath' header files

using namespace std;                   // for standard namespace (predefined keywords in c++)

// (2): Define a Class corresponding to the projectile problem

class projectile
{
    private:
    double x_0, y_0, v_0, h, theta, drag_coeff, mass, g, density, r, q, max_h;

    public:
        void input(void);
        double euler(double a, double b,double c);
        //EXERCISE NO 2: declare a function named 'drag' that has 'double' return type and takes one parameter named 'v'

        //EXERCISE NO 3: declare a function named 'calc' that has 'void' return type and doesn't take any parameters

        //EXERCISE NO 4: declare a function named 'output' that has 'void' return type and doesn't take any parameters

};

//definition for input function
void projectile::input()
{
/* (3): input or initialise initial parameters like initial velocity, launch angle ,
drag coefficient of body etc. */
    g = -9.8;                            // acceleration due to gravity
    h = 0.001;                           // Step Size
    density = 1.225;                      // Air Density At Room Temperature

    //EXERCISE NO 5: define parameters 'max_h', 'x_0' and 'y_0' and assign them all the value '0.0'



    cout<<"Enter the mass of projectile::";
    cin>>mass;
    //EXERCISE NO 6: use the 'cout' command to display the following message: 'Enter the radius of projectile::'

    cin>>r;
    cout<<"Enter the initial velocity with which projectile is launched::";
    //EXERCISE NO 7: use the 'cin' command to ask user to input a value that gets assigned to the varaible 'v_o'

    cin>>v_0;
    cout<<"The angle at which the projectile is launched::";
    cin>>theta;
    cout<<"The drag coefficient for body::";
    cin>>drag_coeff;                     // in case of 0 air resistance input drag_coeff as 0

    theta = (M_PI/180.0)*theta;          // converting the angle from degrees into radians
    double maxx_h = pow((v_0*sin(theta)),2)/(2*9.8);
    cout<<"The Maximum height (Theoretical) achieved without drag is "<<maxx_h<<" Meter\n" ;
    //EXERCISE NO 8: To understand the role of the following conditions, play around with them and see what effect they have on output
    for(double i=0; i<1; i++){

        if(drag_coeff == 0){
            q = 0;
            break;
        }

        else{
            q = 1;
        }
    }
}
// (4): definition of the function to implement the Euler method

double projectile::euler(double a , double b, double c)
{
    return a + b*c ;
}
// (5): definition of the function to compute the acceleration along x- and y-axis

double projectile::drag(double v)
{
    //EXERCISE NO 9: return the following value in this function: 'g - (((density*4*atan(1)*drag_coeff*r*r)/(2*mass))*v*v)'

}

// (6): define a calc() function for calculating the trajectory of projectile

void projectile::calc()
{
    ofstream out("proj_trajectory.txt"); // creating a data file for storing the trajectory data

    double v_x = v_0 * cos(theta);
    //EXERCISE NO 10: create a variable 'v_y' of 'double' data type and assign it the value of perpendicular component of v_0


for(double t=0; t<100; t+=h){
        out<<x_0<<"\t"<<y_0<<"\n";      //  to output the data of position and store it in the file created i.e., "proj_trajectory.txt"


// (7): using numerical method like Euler for solving ODE

        v_x = euler(v_x, q*(drag(v_x) - g), h);       //calling euler function, passing it appropraite variables and assigning the result to a variable
        v_y = euler(v_y, drag(v_y), h);
        //EXERCISE NO 11: Call the function 'euler', pass it the variables 'y_0', 'v_y' and 'h' and assign the result to the variable 'y_0'


        /* this 'if condition' is for breaking the FOR loop when the value of height
        reaches negative for a timestep */
        if(y_0<0)
        {
            break;
        }

        //EXERCISE NO 12: Call the function 'euler', pass it the variables 'x_0', 'v_x' and 'h' and assign the result to the variable 'x_0'

        if(y_0>max_h)       // this 'if condition' is to find the maximum height that projectile a can achieve
        {
           max_h=y_0;
        }
  }
}

void projectile::output()
{
    /* The values of maximum height and range of projectile are computed using the data file generated.
    These values can also be computed using the direct formulas for the range and maximum height of
    projectile as mentioned in the documentation as equation numbers (4) and (5) respectively*/
    cout<<" The maximum height of the projectile is::"<<max_h<<"\n";
    cout<<" The range of the projectile is::"<<x_0;
}
// (8): Create an object for the class Projectile in the main function and call the input() and calc() function
int main()
{
    projectile body;
    body.input();
    //EXERCISE NO 13: call 'calc' and 'output' functions of the object 'body'


    return 0;
}

```
