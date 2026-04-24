#include <iostream>
using namespace std;

int main(){
    int correctPIN = 1234;
    int pin[3];
    int choice, balance = 1000, amount;
    bool login = false;

    for(int i = 0; i < 3; i++){
        cout << "Enter ATM PIN: ";
        cin >> pin[i];

        if(pin[i] == correctPIN){
            login = true;
            cout << "Login Successful\n";
            break;
        } else {
            cout << "Incorrect PIN\n";
        }
    }

    if(login){
        while(true){
            cout << "\n--- ATM Menu ---\n";
            cout << "1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if(choice == 1){
                cout << "Current Balance: " << balance << endl;
            }
            else if(choice == 2){
                cout << "Enter amount to deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Updated Balance: " << balance << endl;
            }
            else if(choice == 3){
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if(amount > 0 && amount <= balance){
                    balance -= amount;
                    cout << "Remaining Balance: " << balance << endl;
                } else {
                    cout << "Insufficient Balance\n";
                }
            }
            else if(choice == 4){
                cout << "Thank you for using ATM\n";
                break;
            }
            else{
                cout << "Invalid Choice\n";
            }
        }
    } 
    else{
        cout << "Too many incorrect attempts. Access Denied.\n";
    }

    return 0;
}