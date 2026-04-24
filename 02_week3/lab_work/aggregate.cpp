#include <iostream>
using namespace std;

int main(){
float matric, inter, ecat, result;
float permatric, perinter, perecat;
string name;
cout<<"enter your name:"; cin>> name;
cout<<"Enter your matric marks (out of 1100): "; cin>> matric;
cout<<"Enter your inter marks(out of 550): "; cin>> inter;
cout<<"enter your ecat marks(out of 400): "; cin>> ecat;

permatric = matric / 1100 * 17;
perinter= inter / 550 * 33;
perecat = ecat / 400 * 50;

result= permatric + perinter + perecat;

cout<< "the aggregate for " << name<< "is "<< result;

};