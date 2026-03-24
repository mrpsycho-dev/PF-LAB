#include <iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter number of elements: "; cin>>n;
  int numbers[n]={};
  cout<<"Enter numbers, one per line: ";
  int x = numbers[0];
  for (int i=0; i<n;i++){
    cin >>numbers[i];
    if(numbers[i]> x){
      x = numbers[i];
    }
    
    
  }
  cout<<"Largest number: "<<x;

}
