#include <iostream>
using namespace std;

int main(){
  
    string word;
    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; word[i] != '\0'; i++){
        
        if (word[i] == 'z') {cout << 'a';}
        else{
          char x = word[i] + 1;
          cout << x;
        }
    }

}
  
//   string word;
//   cout<<"Enter a word "; cin>> word;

//   string alphabets = "abcdefghijklmnopqrstuvwxyza";
//   char alphabets_arr[] = {};  
//   for (int i=0; alphabets[i]!='\0';i++){
//   alphabets_arr[i] = alphabets[i];
//   }
//   int i;
// // int index[]= {};
//   while(word[i] != '\0'){
//      if (word[i] == alphabets_arr[i]){
//       cout<< alphabets_arr[i+1]; 
//     }
    
    
//   }

  