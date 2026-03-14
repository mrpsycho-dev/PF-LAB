#include <iostream>
using namespace std;

int main(){
  int speed;
  cout<<"Enter speed: 0";
  cin>> speed;
  
  if (speed>=0&&speed<=10 ){cout<<"Slow";}
  else if(speed <=50){cout<<"average";}
  else if(speed <=150){cout<<"fast";}
  else if(speed <=1000){cout<<"ultra fast";}
  else if(speed >1000){cout<<"extremely fast";}
  return 0;
}