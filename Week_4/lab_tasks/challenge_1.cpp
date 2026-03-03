#include <iostream>
using namespace std;

int main() {float amount, discount,total;

  cout<<"Enter the amount(Rs:) of things purchased"; cin>> amount;
  
  if (amount < 5000){
    discount = amount*5/100;
 
    
  } if(amount> 5000){
    discount = amount*10/100;
  
  }
  
  total = amount - discount;
cout<< "Discounted price: "<< total; 
  return 0;
};
