#include <iostream>
#include "euler.h"
#include "fn.h"
using namespace std;

class testcode{
    public:
        int i,n;
        string num_method; 
        double x, y, z, a, v, v1, h;
        void input(){
            cout<<"enter velocity"<<endl;
            cin>>v;
            cout<<"enter acceleration"<<endl;
            cin>>a;
            cout<<"enter time step"<<endl;
            cin>>h;
        }
        void solve(){
            if (num_method == "euler"){
                v1 = euler::eulermethod(v,a,h);
            }

            else if(num_method == "fn"){
                v1 = fn::fnmethod(v,a,h);
            }
            cout<<"next velocity is "<< v1 <<endl;
        }
};

int main(){
    testcode obj;
    obj.input();
    obj.solve();
    return 0;
}
