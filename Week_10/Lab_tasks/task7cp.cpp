#include <iostream>
using namespace std;

bool isSymmetrical(int num)
{
  int original = num;
  int reverse = 0;

  while (num > 0)
  {
    int digit = num % 10;
    reverse = reverse * 10 + digit;
    num = num / 10;
  }

  if (original == reverse)
    return true;
  else
    return false;
}

int main()
{
  int number;

  cout << "Enter a 3-digit number: ";
  cin >> number;

  if (isSymmetrical(number))
    cout << "True (Number is symmetrical)";
  else
    cout << "False (Number is not symmetrical)";

  return 0;
}