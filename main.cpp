#include<iostream>
#include "mymath.h"
using namespace std;

int main(){
    float v0 = 10.;
    float t = 10.;
    vecitySolver vs = vecitySolver(v0);
    cout<<"v0="<<v0<<"m/s after"<<t<<"s, v="<<vs.vecity(t)<<endl;
    cout<<"v0="<<v0<<"m/s after"<<t<<"s distance="<<vs.distance(t)<<endl;
    float a = 1.;
    float b = 2.;
    float c = 3.;
    arrow a1 = arrow(a,b,c);
    cout<<a1.norm()<<endl;
    float arr1[4] = {1.,2.,3.,4.};
    float arr2[4] = {4.,5.,6.,7.};
    arrowV a2 = arrowV(arr1, sizeof(arr1)/sizeof(arr1[0]));
    arrowV a3 = arrowV(arr2, sizeof(arr2)/sizeof(arr2[0]));
    cout<<a2[0]<<endl;
    cout<<a2.len()<<endl;
    a2.pop();
    cout<<a2.len()<<endl;
    a2.append(10.);
    arrowV a4 = a2+a3;
    cout<<a3[2]<<endl;
    cout<<a3[4]<<endl;
    return -1;
}
