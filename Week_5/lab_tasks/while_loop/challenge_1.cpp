#include <iostream>
using namespace std;

int main(){
  int n1,n2,gcd;
  cout << "Enter first number: "; cin>> n1;
  cout << "Enter 2nd number: "; cin>> n2;
for (int i=1 ; i <= n1 && i <= n2; i++){
  if(n1%i==0 && n2%i==0){
    gcd = i;
  }
}
  
  
  int lcm = n1*n2/gcd;
  
  cout<< "LCM : "<< lcm << endl << "GCF: " << gcd;
}