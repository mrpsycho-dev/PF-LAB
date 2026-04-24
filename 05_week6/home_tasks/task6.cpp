#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  string arr[n];

  cout << "Enter student names:\n";
  cin.ignore();
  for (int i = 0; i < n; i++){
  getline(cin, arr[i]);
  }

   for (int i = 0; i < n-1; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i]> arr[j]){
        string temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  cout<<"The sorted names: ";
  for (int i = 0; i < n; i++){
    cout<< arr[i];
  }
  
  
}