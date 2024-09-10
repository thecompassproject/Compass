```cpp
// (1): Include All Necessary Header files

#include <iostream>                    // <iostream> for input(cin) and output(cout) function
//EXERCISE NO 1: Include 'iostream' and 'cmath' header files


using namespace std;                   // for standard namespace (predefined keywords in c++)

// (2): Define a Class corresponding to the Lorenz convection system

class lorenz{

    double x, y, z, h, n, sig, rho, beta;

    public:
        //declare public member functions here
        void input(void);
        //EXERCISE NO 2: declare a function named 'calc' that has 'void' return type and takes no parameter

        double function1(double xx, double yy);
    	//EXERCISE NO 3: declare two functions named 'function2' and 'function3', both having 'double' return type and each admitting three parameters: 'xx', 'yy' and 'zz' all having 'double' data type


};
        //definition for input function
void lorenz::input()
{
/* (3): input or initialise initial parameters like  Prandtl number, Rayleigh Number,
ratio of physical dimensions of layer, step-size etc. */

    cout<<"\n Enter the Prandtl number (ratio of viscosity to thermal diffusivity):";
    cin>>sig; // lorenz chose 10

    //EXERCISE NO 4: use the 'cout' command to display the following message: 'Enter the Rayleigh Number:'

    cin>>rho; // lorenz chose 28

    cout<<"\n Enter the ratio of physical dimensions of layer:";
	//EXERCISE NO 5: use the 'cin' command to ask user to input value that gets assigned to the variable 'beta'

    cout<<"\n Enter the initial value of convective flow:";
    cin>>x;

    cout<<"\n Enter the initial variation in horizontal temperature value:";
    cin>>y;

    cout<<"\n Enter the initial variation in vertical temperature value:";
    cin>>z;

    cout<<"\n Enter the time step:";
    cin>>h;

    //EXERCISE NO 6: use the 'cout' command to display the following message: 'Enter the number of steps:

    //EXERCISE NO 7: use the 'cin' command to ask user to input value that gets assigned to the variable 'n'

}
// (4): define required extrenal functions to return the following

        //  ODE for evolution in rate of convection
double lorenz::function1(double xx,double yy){
       return sig*(yy-xx);
}
        // ODE for evolution in horizontal temperature value
double lorenz::function2(double xx,double yy,double zz){
    return (xx*(rho-zz))-yy;
}
        // ODE for evolution in vertical temperature value
double lorenz::function3(double xx,double yy,double zz){
    //EXERCISE NO 8: return the following value: '(xx*yy-beta*zz)'

}

// (6): define a calc() function to simulate the evolution of the system
void lorenz::calc(){

ofstream outfl("lorenz.dat"); // creating a data file for storing the data corresponding to evolution of the system

    for(double t=0;t<n;t++){

        outfl<<x<<"\t"<<y<<"\t"<<z<<"\n";
// (7): using numerical method like Euler for solving the obove defined ODEs
        x += function1(x,y)*h;

		//EXERCISE NO 9: Update the value of variable 'y' by adding the following to its previous value: the product of the variable 'h' and the value returned by the function 'function2' when the variables 'x', 'y' and 'z' passed to it.


        z += function3(x,y,z)*h;
    }
}
// (8): Create an object for the class lorenz in the main function and call the input() and calc() function
int main(){

    lorenz system;
    object.input();
    //EXERCISE NO 10: call 'calc' function of the object 'system'

    return 0;
}

/*ADDITIONAL EXERCISES:
1. Read the program documentation and try solving the problem using other numerical methods and observe which one is more acccurate
2. Observe the effect of changing the value of time step, 'h'
3. Observe the effect of taking values of variables 'sig', 'rho' and 'beta' different from those Lorenz used in his calculation
4. Play with limits of 'for' loop in the 'calc' function and observe the effects
*/

```
