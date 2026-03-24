#include <iostream>
using namespace std;

int main(){
  int n; cin>> n;
  int numbers[n];
  int even=0;
 
  for (int i=0;i<n;i++){
    cin>> numbers[i];
 
 if(numbers[i]%2 ==0){
   even++;
 }
}
cout<<"Even: "<<even;
}