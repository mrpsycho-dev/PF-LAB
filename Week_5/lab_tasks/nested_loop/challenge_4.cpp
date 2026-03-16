#include <iostream>
using namespace std;

int main(){
  
  int pin;
  float money= 999999, depositAmount, withdrawAmount;
  cout<<"Enter PIN: ";
  cin>>pin;
  
  if (pin == 1234){
    cout<< "Login Successful";
    cout<<R"(
    
    ----------ATM MENU-------------
    1. Check Balance
    2. Deposit Money
    3. Withdraw Money
    4. Exit
    
    )";
    
    int x;
    cin>>x;
    
    if(x==1){
      cout<<"Current Account Balance: $" << money;
    }
    else if (x==2){
      cout<<"Deposit Money: ";
       cin>> depositAmount;
       money = money + depositAmount;
       return money;
      
    }else if (x==3){
      cout<<"Withdraw Money: ";
       cin>> withdrawAmount;
       if (money> withdrawAmount){
        money = money - withdrawAmount;
       }else {
        cout<<"Insufficient Balance. ";
       }
       return money;
      
    }else if (x==4){
      cout<<"Program Ends.";
      return 0;
    }else {
      
      cout<<"Enter a valid choice.";
    }
    
  }
  
  
}