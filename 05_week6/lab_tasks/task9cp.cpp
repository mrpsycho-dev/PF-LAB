#include <iostream>
using namespace std;

int main(){
  int arr [4];
  float bill, amount;
  
  cout<<"Enter quarters: "; cin>> arr[0];
  cout<<"Enter dimes: "; cin>> arr[1];
  cout<<"Enter nickles: "; cin>> arr[2];
  cout<<"Enter pennies: "; cin>> arr[3];
  
  cout<<"Enter the total amount due: $"; cin>> bill;
  
  amount = (arr[0]*0.25) + (arr[1]* 0.1) + (arr[2]*0.05) + (arr[3]*.01);
  if (amount >= bill){
    cout<<"You can pay the bill";
  }else{
    
    cout<<"You can not pay the bill";
  }
  
  
}
