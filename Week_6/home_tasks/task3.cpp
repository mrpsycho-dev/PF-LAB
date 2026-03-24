#include <iostream>
using namespace std;

int main(){
  int n; cin>> n;
  int numbers[n];
 
  for (int i=0;i<n;i++){
    cin>> numbers[i];
  }
  
   int largest = numbers[0];
   int smallest = numbers[0];
    
  for (int i=0;i<n;i++){
 if(largest> numbers[i]){
    largest = numbers[i];
 }
if(smallest> numbers[i]){
    smallest = numbers[i];
 }

}
cout<<"Largest: "<<largest;
cout<<"Smallest: "<<smallest;
}