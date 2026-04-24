#include <iostream>
using namespace std;

bool isStrong(int num);
int factorial(int num);
int main()
{
  int num;
  cin >> num;
  if (isStrong(num))
  {
    cout << "The number is strong";
  }
  else
  {
    cout << "The number is not strong";
  }
}
bool isStrong(int num)
{
  int x, y = 0, originalNum = num;
  while (num > 0)
  {
    x = num % 10;
    y = y + factorial(x);
    num /= 10;
  }
  if (y == originalNum)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int factorial(int num)
{
  int i = 1;
  int fact = 1;
  while (i <= num)
  {
    fact = fact * i;
    i++;
  }
  return fact;
}