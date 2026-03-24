#include <iostream>
using namespace std;

int main(){
  int n;
  int numbers[n]={};
  cout<<"Enter number of elements: "; cin>>n;
  cout<<"Enter numbers, one per line: ";
  
  for (int i=0; i<n; i++){
    cin>>numbers[i];
  }
  for (int i=n-1; i>=0; i--){
    
    cout<<" "<<numbers[i];
  }

}
