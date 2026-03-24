#include <iostream>
using namespace std;

int main(){
  int n; cin>> n;
  int numbers[n];
  int largest, smallest;
 
  for (int i=0;i<n;i++){
    cin>> numbers[i];
    largest = numbers[0];
    smallest = numbers[0];
    
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