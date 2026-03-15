#include <iostream>
using namespace std;

int main(){
  int num, x, digits = 0,y= 0;
  cout<<"Enter number: "; cin>> num;
  cout<<"Enter digit: "; cin>> x;
  
  for(int i = num; i > 0; i = i / 10) {
   y = num%10;
    if (y == x){
      digits+=1;
    }
    num /=10;

    
}
  cout<<"frequency: "<< digits;
}