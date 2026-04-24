#include <iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter number of resistors in series: "; cin>>n;
  float numbers[n]={};
  cout<<"Enter resistance value(ohm), one per line: ";
  float x = 0;
  for (int i=0; i<n;i++){
    cin >>numbers[i];
   x+= numbers[i];
  }
  cout<<"Total resistance: "<<x;

}
