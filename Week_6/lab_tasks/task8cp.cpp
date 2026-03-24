#include <iostream>
using namespace std;

int main(){
  int arr1[2];
  int n;
  
  for (int i=0; i<2;i++){
    cin>>arr1[i];
  }
  cout<<"Enter number of elements in 2nd array: "; cin>> n;
  int arr2[n]={};
  int finalArray[n+1];
   for (int i=0; i<n;i++){
    cin>>arr2[i];
       // Why can't we use this simple line?
       // finalArray[i+2]={arr1[0],arr2[i] , arr1[1]};
       // finalArray[arr1[0],arr2[i] , arr1[1]];
    
  }
  finalArray[0] = arr1[0];
  for(int i =1; i<=n;i++){
    
    finalArray[i] = arr2[i-1]; 
  }
  finalArray[n+1] = arr1[1];
   
 cout << "Final Array: [";
 for (int i = 0; i < n + 2; i++){
   cout << finalArray[i];
   if(i!=n+1){cout<<", ";}
  }
  cout << "]";
}