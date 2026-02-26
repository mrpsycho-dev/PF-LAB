#include <iostream>
using namespace std;
int main(){

int wins, loses, draws, total;
cout<<"enter number of wins: "; cin>> wins;
cout<<"enter number of loses: "; cin>> loses;
cout<<"enter number of draws: "; cin>> draws;

wins = wins *3;
loses = 0;

total = wins + draws;


cout<<"pakistan got total " << total << "points.";

};