#include <iostream>
using namespace std;

int main(){
 string personName;
 float kgToLose, requiredDays;
 cout<<"Enter your name: ";
 cin>>personName;
 cout<<"How many kilograms do you want to lose: ";
 cin>>kgToLose;
 requiredDays = kgToLose * 15;
 cout<<personName<<" will need about "<<requiredDays<<" days to reach the goal";
 return 0;
};
