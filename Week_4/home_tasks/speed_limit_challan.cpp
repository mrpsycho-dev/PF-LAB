#include <iostream>
using namespace std;

int main() {
  
  int speed;

  cout << "Speed: "; cin >> speed;

  if (speed > 100) {
    cout << "Halt...!!! YOU WILL BE CHALLANED!";
  } else {
    cout << "Perfect! You're going good.";
  }

  return 0;
};
