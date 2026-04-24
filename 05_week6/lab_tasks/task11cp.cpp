#include <iostream>
using namespace std;

int main (){
 char vowels[5]= {'a','e','i','o','u'};
 
 string line; 
 getline(cin, line);
//  cin >> line;
 
 for (int i=0; i<line.length(); i++){
   bool isVowel = false;
  for (int j=0; j<5; j++){
    if (line[i] == vowels[j]){
     isVowel = true;
     break;
    }
  }
if(!isVowel){cout<<line[i];}

}
 
  
}