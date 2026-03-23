#include <iostream>
using namespace std;

int main(){
  
  string word;
  cout<<"Enter a word "; cin>> word;
  
  // for (int i=word.length() -1; i>=0; i--){
  //   cout<<word[i];}
  
  int i = 0;

while (word[i] != '\0'){i++;}

while (i--){cout << word[i];}
    
}
  
  
  
