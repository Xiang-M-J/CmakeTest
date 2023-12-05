#include "mymath.h"

vecitySolver::vecitySolver(float v0)
{
    this->v0 = v0;
}

vecitySolver::vecitySolver(){
    this->v0 = 0;
}

vecitySolver::~vecitySolver()
{
}

float vecitySolver::vecity(float t){
    return v0 + g * t;
}

float vecitySolver::distance(float t){
    return v0 * t + 0.5 * g * t;
}

arrow::arrow(float x, float y, float z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

arrow::~arrow()
{
}

float arrow::norm(){
    return sqrt(this->x * this->x + this->y*this->y+this->z+this->z);
}

arrow arrow::operator+(arrow &other){
    return arrow(this->x+other.x, this->y+other.y, this->z+other.z);
}

arrow arrow::operator-(arrow &other){
    return arrow(this->x-other.x, this->y-other.y, this->z-other.z);
}

arrow arrow::operator*(arrow &other){
    return arrow(this->x*other.x, this->y*other.y, this->z*other.z);
}

arrowV::arrowV(float arr[], int n)
{
    // int size = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < n; i++)
    {
        this->arr.push_back(arr[i]);
    }
}

arrowV::~arrowV()
{
    this->arr.clear();
    this->arr.shrink_to_fit();
}

bool arrowV::append(float v){
    // try
    // {
    this->arr.push_back(v);
    // }
    // catch(std::exception e){
    //     return false;
    // }
    return true;
}

bool arrowV::pop(){
    if (this->arr.size() > 0)
    {
        this->arr.pop_back();
        return true;
    }
    else{
        return false;
    }
}

int arrowV::len(){
    return this->arr.size();
}

float arrowV::operator[](int idx){
    if (idx < this->arr.size())
    {
        return this->arr.at(idx);
    }
    else{
        printf("%d over size", idx);
    }
    return -1;
}

arrowV arrowV::operator+(arrowV & other){
    if (other.arr.size() != this->arr.size())
    {
        throw("size do not match");
    }
    const int N = this->arr.size();
    float arr[N];
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = this->arr.at(i) + other.arr.at(i);
    }
    return arrowV(arr, N);
}

arrowV arrowV::operator-(arrowV & other){
    if (other.arr.size() != this->arr.size())
    {
        throw("size do not match");
    }
    const int N = this->arr.size();
    float arr[N];
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = this->arr.at(i) - other.arr.at(i);
    }
    return arrowV(arr, N);
}

arrowV arrowV::operator*(arrowV & other){
    if (other.arr.size() != this->arr.size())
    {
        throw("size do not match");
    }
    const int N = this->arr.size();
    float arr[N];
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = this->arr.at(i) * other.arr.at(i);
    }
    return arrowV(arr, N);
}

bool arrowV::clear(){
    this->arr.clear();
    return true;
}
float arrowV::norm(){
    float v = 0;
    for (size_t i = 0; i < this->arr.size(); i++)
    {
        v += this->arr.at(i);
    }
    return sqrt(v);
}
