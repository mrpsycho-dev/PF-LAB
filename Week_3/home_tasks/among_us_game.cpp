#include<iostream>
using namespace std;

int main(){
  
int impCount, playerCount, chancePercent;
cout<<"Enter number of imposters: ";
cin>>impCount;
cout<<"Enter total players: ";
cin>>playerCount;
chancePercent=(impCount/playerCount)*100;
cout<<"Chance of being imposter: "<<chancePercent<<"%"<<endl;

return 0;

};
