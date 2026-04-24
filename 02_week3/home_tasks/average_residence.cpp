#include <iostream>
using namespace std;

int main(){
  
 float currentAge, totalMoves;
 float avgYears;
 cout<<"Enter current age: ";
 cin>>currentAge;
 cout<<"How many times have you moved: ";
 cin>>totalMoves;
 avgYears = currentAge / (totalMoves + 1);
 cout<<"Average years per house: "<<avgYears;
 
 return 0;
 
};
