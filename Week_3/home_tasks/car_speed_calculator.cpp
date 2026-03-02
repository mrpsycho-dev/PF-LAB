#include<iostream>
using namespace std;

int main(){
  
 float initVel,acc,timeSec,finalVel;
 cout<<"Enter Initial Velocity: ";
 cin>>initVel;
 cout<<"Enter Acceleration: ";
 cin>>acc;
 cout<<"Enter Time: ";
 cin>>timeSec;
 finalVel=initVel+(acc*timeSec);
 cout<<"Final Velocity: "<<finalVel<<" m/s"<<endl;
 return 0;
};
