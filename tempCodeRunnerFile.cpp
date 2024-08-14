// (1): Include All Necessary Header files

#include<iostream>                     // <iostream> for input(cin) and output(cout) function
#include<fstream>                      // <fstream> to input/output data into/from data files
#include<cmath>                        // <cmath> for predefined mathematical functions 

using namespace std;                   // for standard namespace (predefined keywords in c++)

// (2): Define a Class corresponding to the projectile problem

class projectile
{
    private:
    double x_0, y_0, v_0, h, theta, drag_coeff, mass, g, density, r, q ;
    double max_h ;
    
    public:
        void input(void);   
        double euler(double a, double b, double c);
        double drag(double v);
        void calc(void);
        void output(void);
};

void projectile::input()
{
/* (3): input or initialise initial parameters like initial velocity, launch angle ,
drag coefficient of body etc. */ 
    g = -9.8;                            // acceleration due to gravity
    h = 0.001;                           // Step Size
    max_h = 0.0;
    x_0 = 0.0 ;
    y_0 = 0.0 ;
    density = 1.225;                      // Air Density At Room Temperature
    cout<<"Enter the mass of projectile::"<<endl;
    cin>>mass;
    cout<<"Enter the radius of projectile::"<<endl;
    cin>>r;
    cout<<"Enter the initial velocity with which projectile is launched::"<<endl;
    cin>>v_0;
    cout<<"The angle at which the projectile is launched::"<<endl;
    cin>>theta;
    cout<<"The drag coefficient for body::"<<endl;
    cin>>drag_coeff;                     // in case of 0 air resistance input drag_coeff as 0
    
    theta = (M_PI/180.0)*theta;          // converting the angle from degrees into radians 
    double maxx_h = pow((v_0*sin(theta)),2)/(2*9.8) ;
    cout<<"The Maximum height (Theoretical) achieved without drag is "<<maxx_h<<" Meter\n" ;
    for(double i =0 ;i<1;i++){
        
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

double projectile::euler(double a, double b, double c)
{
    return a + b*c ;
}
// (5): definition of the function to compute the acceleration along x- and y-axis

double projectile::drag(double v)
{
    return g - (((density*4*atan(1)*drag_coeff*r*r)/(2*mass))*v*v) ;
}

// (6): define a calc() function for calculating the trajectory of projectile

void projectile::calc()
{
   
    
    ofstream out("proj_trajectory.txt"); // creating a data file for storing the trajectory data 
    
    double v_x = v_0 * cos(theta) ;
    double v_y = v_0 * sin(theta) ;
    
for(double t=0 ;t<100 ;t+=h){
                                         //  to output the data of position and store it in the file created i.e., "proj_trajectory.txt"
        out<<x_0<<"\t"<<y_0<<"\n"; 

        
// (7): using numerical method like Euler for solving ODE  
        
        v_x = euler(v_x ,q*(drag(v_x) - g) ,h) ;
        v_y = euler(v_y ,drag(v_y) ,h) ;
        y_0 = euler(y_0 ,v_y ,h) ;
        /* this 'if condition' is for breaking the FOR loop when the value of height 
        reaches negative for a timestep */
        if(y_0<0)
        {
            break ;
        }
        
        x_0 = euler(x_0 ,v_x ,h) ;
        
                                         // this 'if condition' is to find the maximum height that projectile a can achieve
        if(y_0>max_h)
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
    body.calc();
    body.output();
    return 0;
}