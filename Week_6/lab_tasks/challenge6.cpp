#include <iostream>
using namespace std;

int main(){
  string username, enteredUsernames[3];
  int pass;
  bool success = false;
  
  cout<<"Enter credentials: ";
  for(int i=0;i<3;i++){
    cout<<"Username: "; cin>> username;
    cout<<"Pass: "; cin>> pass;
  enteredUsernames[i] = username;
  if (username == "admin"&& pass == 1234){
    success = true;
    cout<< "Login successful.";
  } else {cout<<"Incorrect user or pass";}
}

string studentName_array[3], courseName_array[3];
int age_array[3];

int count = 0;

while(true){
  
  if(success){
    cout<<R"(
      -------------------------
      •	1 → Add Student
      •	2 → View Students
      •	3 → Add Course
      •	4 → View Courses
      •	5 → Exit
      -------------------------
      
      )";
      int option; cin>> option;
      if(option == 1){
        if(count < 3){
        string studentName;
        int age;

        cout << "Enter name: ";
        cin >> studentName;
        cout << "Enter age: ";
        cin >> age;

        studentName_array[count] = studentName;
        age_array[count] = age;

        count++; 
    } else {
        cout << "Array full!\n";
    }
   } else if (option == 2){
    for (int i=0; i<3; i++){
      cout<<studentName_array[i]<<endl;
      cout<<age_array[i]<<endl;
    }
   }
      else if (option == 3){
        if(count<3){
          
          string courseName;
          cin>> courseName;       
          courseName_array[count] = courseName;
      }
    }
      else if (option == 4){
        for(int i=0; i<3;i++){ 
          cout<<courseName_array[i];    
        }
      }
      else if (option == 5){return 0;}
    }
      
}

}