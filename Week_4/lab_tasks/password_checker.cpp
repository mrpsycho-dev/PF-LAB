#include <iostream>
using namespace std;

int main() {

  string myPass, passChecker;
  
  myPass = "Abdullah$(&*)*()";
  cout<<"Try to guess my pass: "; cin>> passChecker;
  if (myPass == passChecker){
    cout<<"You cracked the thing!!";
    
  }else {
    cout<<"its not that easy ....";
  }

  return 0;
}