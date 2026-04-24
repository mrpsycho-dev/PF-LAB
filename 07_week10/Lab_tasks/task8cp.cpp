#include <iostream>
using namespace std;

string OddishOrEvenish(int num)
{
  int sum = 0;

  while (num > 0)
  {
    int digit = num % 10;
    sum += digit;
    num = num / 10;
  }

  if (sum % 2 == 0)
    return "Evenish";
  else
    return "Oddish";
}

int main()
{
  int number;

  cout << "Enter a 5-digit number: ";
  cin >> number;

  string result = OddishOrEvenish(number);

  cout << result;

  return 0;
}