#include <iostream>
using namespace std;

int main(){
 int volt, current, power;
 
 cout<<"Enter voltage: "; cin>> volt;
 cout<<"Enter current: "; cin>> current;
 power = volt * current;
 
 cout <<"Power is " << power << " watts.";
  
};