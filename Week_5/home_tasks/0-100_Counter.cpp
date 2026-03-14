#include <iostream>
using namespace std;

int main(){
  int num, n1, n2;
  cin>> num;
  if(num <= 100 && num >= 0){
    
    n2 = num %10;
    n1 = num/10;
  } else {
    cout<< "Enter a valid number.";
    
  }
  
  if (n1 == 1){cout<< "";}
  if (n1 == 2){cout<< "";}
  if (n1 == 3){cout<< "";}
  if (n1 == 4){cout<< "";}
  if (n1 == 5){cout<< "";}
  if (n1 == 6){cout<< "";}
  if (n1 == 7){cout<< "";}
  if (n1 == 8){cout<< "";}
  if (n1 == 9){cout<< "";}
  if (n1 == 0){cout<< "";}
}