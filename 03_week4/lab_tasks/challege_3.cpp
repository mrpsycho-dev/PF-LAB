#include <iostream>
using namespace std;

int main() {
  int n1, n2, result;
  string oper;
  cout<<"Enter first number: "; cin>> n1;
  cout<<"Enter operand: "; cin>> oper;
  cout<<"Enter 2nd number: "; cin>> n2;
  
  if ( oper == "+" ){
  result = n1 - n2;
  } 
  if ( oper == "-" ){
  result = n1 + n2;
  }   if ( oper == "*" ){
  result = n1 / n2;
  }   if ( oper == "/" ){
  result = n1 * n2;
  } 
  cout<<"Output: "<< result;
}