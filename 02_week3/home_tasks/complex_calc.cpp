#include <iostream>
using namespace std;

int main(){

 int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
 
 int sumPart,multiplyPart,subtractPart,finalAnswer;
 
 cout<<"Enter 15 numbers to perform calculations: ";
 cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15;
 
 sumPart = a1 + a2 + a3 + a4 + a5;
 multiplyPart = a6 * a7 * a8 * a9 * a10;
 subtractPart = a11 - a12 - a13 - a14 - a15;
 finalAnswer = (sumPart + multiplyPart) - subtractPart;
 
 cout<<"Final result is: "<<finalAnswer;
 return 0;
 
};
