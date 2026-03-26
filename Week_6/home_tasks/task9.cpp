#include<iostream>
using namespace std;

int main(){
  int choice;
  int n = 0;

  string bookNames[100];
  int quantity[100];

  while(true){
    cout << R"(

 ----------- Library Menu -----------
 1. Add Books
 2. View Books
 3. Borrow Books
 4. View Available Books
 5. Exit
 -----------------------------------
 )";

    cout << "Enter your choice: "; cin >> choice;

    if(choice == 1){
      int add;
      cout << "How many books to add: "; cin >> add;

      for(int i = 0; i < add; i++){
        cout << "Enter name of book " << n+1 << ": "; cin >> bookNames[n];
        cout << "Enter quantity of " << bookNames[n] << ": ";  cin >> quantity[n];        
        n++;
      }
    }

    else if(choice == 2){
      cout << "\n----------- All Books -----------\n";
      
      for(int i = 0; i < n; i++){
        cout << bookNames[i] << " : " << quantity[i] << " copies" << endl;
      }
    }
    
    else if(choice == 3){
      string borrow;
      cout << "Enter book name to borrow: ";
      cin >> borrow;

      bool found = false;
      
      for(int i = 0; i < n; i++){
        if(bookNames[i] == borrow){
          found = true;
          
          if(quantity[i] > 0){
            quantity[i]--;
            cout << "Book borrowed successfully!\n";
          } else {
            cout << "Book out of stock!\n";
          }
        }
      }
      
      if(!found){
        cout << "Book not found!\n";
      }
    }
    
    else if(choice == 4){
      cout << "\n-------- Available Books --------\n";

      for(int i = 0; i < n; i++){
        if(quantity[i] > 0){
          cout << bookNames[i] << " : " << quantity[i] << " copies" << endl;
        }
      }
    }

    else if(choice == 5){
      cout << "Programs ends.";
      return 0;
    }

    else{
      cout << "Invalid choice!\n";
    }
  }
}
