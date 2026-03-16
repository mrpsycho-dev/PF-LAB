#include <iostream>
using namespace std;

int main(){
  
  int pin;
  float money= 999999, depositAmount, withdrawAmount;
  cout<<"Enter PIN: ";
  
  bool loggedIn = false;
  for (int i=1; i<=3; i++){
    cin>>pin;
    if (pin == 1234){loggedIn = true;}
    if(loggedIn){
      cout<< "Login Successful\n";
      break;
      
    } else {
      cout<< "Login failed.\n";
      
    }
    
  }
  if(!loggedIn){
cout<<"Too many attempts.\n";
return 0;
}
 
while(loggedIn){
  
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
       
      
    }else if (x==3){
      cout<<"Withdraw Money: ";
       cin>> withdrawAmount;
       if (money>= withdrawAmount){
        money = money - withdrawAmount;
       }else {
        cout<<"Insufficient Balance. ";
       }
      
      
    }else if (x==4){
      cout<<"Program Ends.";
      return 0;
    }else {
      
      cout<<"Enter a valid choice.";
    }
    
  
}
  
}