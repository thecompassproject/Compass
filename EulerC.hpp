#include <functional>
template<typename Func1, typename Func2>
void calc4(Func1 fx1, Func2 fx2, double& x1, double& x2, double& v1, double& v2, double h){
    
double elr_x1 = h * v1;
double elr_x2 = h * v2;

double elr_v1 = h * fx1(x1, x2, v1, v2);
double elr_v2 = h * fx2(x1, x2, v1, v2);

x1 += elr_x1;
x2 += elr_x2;
v1 += elr_v1;
v2 += elr_v2;
}

