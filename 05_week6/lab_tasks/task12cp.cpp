#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int arr[n];
  bool special = true;
  for (int i=0; i<n; i++){
    cin>> arr[i];
    
    
    if(i%2 == 0){
      if(arr[i] %2 != 0){
       special = false;
      } else {
        if(arr[i] %2 == 0){
       special = false;
      } 
      }
    }
  }
  if (special){
    
    cout<<"The array is special";
  }else {
    cout<<"The array is not special";
    
  }
  
  
  }
 
