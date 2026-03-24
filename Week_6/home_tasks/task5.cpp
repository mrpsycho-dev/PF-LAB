#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  string arr[n];
  int count = 0;
  char letter;

  cout << "Enter student names:\n";
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "Enter letter to check: ";
  cin >> letter;

  for (int i = 0; i < n; i++){
    if(arr[i][0] == letter){
      count++;
    }
  }

  cout << "Total names starting with " << letter << " = " << count;
}