#include <iostream>
using namespace std;

int main(){
  int n; cin>> n;
  string arr[n];
  int count = 0;
  char letter;
  cout<< "Enter student names: \n";
  for (int i=0; i<5; i++){
    cin>> arr[i];
    cout<<"Enter letter to check: "; cin>>letter;
    
    for (int j=0; j<5; j++){
      
      if(arr[i][j]== letter){
      count++;  
      }
      
      
      
    }
  }
  
  
  cout<<"Total names starting with "<< letter << count;
  
}