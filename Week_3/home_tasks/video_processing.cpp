#include<iostream>
using namespace std;

int main(){
 int mins,fpsRate,frameTotal;
 cout<<"Number of Minutes: ";
 cin>>mins;
 cout<<"Frames Per Second: ";
 cin>>fpsRate;
 frameTotal=mins*60*fpsRate;
 cout<<"Total Number of Frames: "<<frameTotal<<endl;
 return 0;
};
