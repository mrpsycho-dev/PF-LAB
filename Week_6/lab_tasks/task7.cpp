#include <iostream>
using namespace std;

int main(){

  string word;
  char letter ;
  bool isFound = false;

  cout<<"Enter a word"; cin>> word;
  cout<<"Enter the letter"; cin>> letter;
  
  for (int i=0; word[i]!='\0'; i++ ){
    
    if(word[i] == letter){
      isFound = true;
    }
    
  }
  
  if(isFound){cout<<"The letter "<<letter <<  "is found in "<< word;}
  else{cout<<"The letter "<<letter <<  "is not found in "<< word;}
  
}