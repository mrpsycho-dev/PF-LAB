#include <iostream>
using namespace std;

int main(){
  string user , pass;
  string name, courseName; int age;
  
  cout <<"UNIVERSITY MANAGEMENT SYSTEM";
  cout<<"Enter Username: "; cin >> user;
  cout<<"Enter Password: "; cin >> pass;
  
  for (int i= 0 ; i<3; i++){
    
    if (user == "admin" && pass == "1234"){
      cout<< "Login Successful";
      
      cout<< R"(
      1. Add Student
      2. View Student
      3. Add Course
      4. Exit)";
      int x;
      cin>>x;
      if(x==1){
        cout<< "Enter Name: "; cin>> name;
        cout<< "Enter Age: "; cin>> age;
  
        
      }
      if(x==2){
        if(name!=""){
          
          cout<< name<< endl<< age;
        }else {cout<< "no data found";}
      }
     else if (x==3){
        cout<< "Enter course name: "; cin>>courseName;
        cout<<"course added: "<< courseName;
      }
     else if (x==4){
        cout<<"Program ends";
        return 0;
      } else {cout<<"Invalid choice.";}
      
    }else {
      
      cout<< "Wrong username or password.";
    }
    if (i==3 && (user!= "admin" || pass!= "1234" )){
      cout<< "3 wrong login attempts. ";
return 0 ;  
    }
  }
  
 
  
}