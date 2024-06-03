#include <functional>
template<typename Func1, typename Func2>
void calc5(Func1 fx1, Func2 fx2, double& x1, double& x2, double& v1, double& v2, double h){
    
double fn_x1 = (h/2) * v1;
double fn_x2 = (h/2) * v2;

double fn_v1 = (h/2) * fx1(x1, x2, v1, v2);
double fn_v2 = (h/2) * fx2(x1, x2, v1, v2);

x1 += fn_x1;
x2 += fn_x2;
v1 += fn_v1;
v2 += fn_v2;
}

