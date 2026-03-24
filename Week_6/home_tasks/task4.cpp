#include <iostream>
using namespace std;

int main(){
  string arr[5];
  cout<< "Enter student names: \n";
  for (int i=0; i<5; i++){
    cin>> arr[i];
  }
  
  cout<<"Student names are: ";
  for (int i=0;i<5;i++){
  cout<< arr[i]<<endl;
  }
  
}