#include <iostream>
using namespace std;

int main() {
int code, d1,d2,d3,d4, result;
cout <<"enter pin"; cin>> code;

d1 = code % 10;
code = code/10;

d2 = code % 10;
code = code/10;

d3 = code % 10;
code = code/10;

d4 = code % 10;
code = code/10;

d1= (d1 +7) %10;
d2= (d2 +7) %10;
d3= (d3 +7) %10;
d4= (d4 +7) %10;

cout << d4 << d3 << d2 << d1;
}