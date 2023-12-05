#include<cmath>
#include<vector>
#include<exception>
#include<stdio.h>

#define PI 3.1415926
#define g 9.98
#define e 2.718

class vecitySolver
{
private:
    float v0;
public:
    vecitySolver(float v0);
    vecitySolver();
    float vecity(float t);
    float distance(float t);
    ~vecitySolver();
};


class arrow
{
private:
    float x;
    float y;
    float z;
public:
    arrow(float x, float y, float z);
    ~arrow();
    float norm();
    arrow operator+(arrow & other);
    arrow operator-(arrow & other);
    arrow operator*(arrow & other);
};

class arrowV
{
private:
    int N;
    std::vector<int> arr;  
public:
    arrowV(float a[], int n);
    ~arrowV();
    bool append(float v);
    bool pop();
    float operator[](int idx);
    arrowV operator+(arrowV & other);
    arrowV operator-(arrowV & other);
    arrowV operator*(arrowV & other);
    int len();
    bool clear();
    float norm();
};

