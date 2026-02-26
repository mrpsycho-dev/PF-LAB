#include<iostream>
using namespace std;

int main(){
  int population, birthRate, population3decades;
  
  cout<< "Enter current world population: "; cin>> population;
  cout<< "Enter current birth rate per month: "; cin>> birthRate;
  
  population3decades = population + (30*12*birthRate);
  
  cout<<"Population in 3 decades will be: " << population3decades;
  return 0;
};