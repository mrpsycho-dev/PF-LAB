#include<iostream>
using namespace std;

int main(){
 int sideCount,totalAngles;
 cout<<"Enter number of sides: ";
 cin>>sideCount;
 totalAngles=(sideCount-2)*180;
 cout<<"Sum of internal angles = "<<totalAngles<<" degrees"<<endl;
 return 0;
};
