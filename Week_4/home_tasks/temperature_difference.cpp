#include <iostream>
using namespace std;

int main() {
  int temp1, temp2;
  cout << "Temperature City 1: ";
  cin >> temp1;

  cout << "Temperature City 2: ";
  cin >> temp2;

  if (abs(temp1 - temp2) > 10) {
    cout << "Difference is too Big" << endl;
  }else{
    
    cout << "Difference is normal.";
    
  }
  
  return 0;
};
