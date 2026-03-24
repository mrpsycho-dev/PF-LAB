#include <iostream>
using namespace std;

int main(){
  
  int n; cin>>n;
  string chords[n];
  
  for (int i=0; i<n; i++){
    cin>>chords[i];
    
    char last = chords[i][chords[i].length() - 1];
    if(last != '7'){
      // cout<< chords[i]<<"7"<<endl;
      chords[i]+="7";
    } 
  }
  
  
  for (int i=0; i<n; i++){
  cout<< chords[i]<< endl;
  }
  
}