#include <iostream>
using namespace std;

int main() {
  int redRose, whiteRose, tulips;
  float totalPrice, finalPrice;

  cout << "Red Rose: ";
  cin >> redRose;

  cout << "White Rose: ";
  cin >> whiteRose;

  cout << "Tulips: ";
  cin >> tulips;

  totalPrice = (redRose * 2) + (whiteRose * 4.1) + (tulips * 2.5);

  cout << "Original Price: " << totalPrice << endl;

  if (totalPrice > 200) {
    finalPrice = totalPrice * 0.8;
    cout << "Price after Discount: " << finalPrice;
  }

  return 0;
}