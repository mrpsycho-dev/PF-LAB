#include <iostream>
using namespace std;

int main(){
  
  string word;
  cout<<"Enter a word "; cin>> word;
  
  for (int i=0; word[i]!='\0'; i++){
    
    cout<<word[i]<<" is found at position "<< i<<endl;
    
  }
  
  
  
}