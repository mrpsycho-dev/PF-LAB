#include <iostream>
using namespace std;

float calculateBalance(float balance, int years);
int main()
{
  float balance;
  int years;
  cout << "Enter balance and years: ";
  cin >> balance >> years;

  float result = calculateBalance(balance, years);
  cout << "Final balance: " << result;
}
float calculateBalance(float balance, int years)
{
  float interest = 0;
  if (balance <= 10000)
  {
    interest = balance * 0.05;
  }
  else if (balance > 10000 && balance <= 50000)
  {
    interest = balance * 0.07;
  }
  else if (balance > 50000)
  {
    interest = balance * 0.1;
  }
  if (years >= 3)
  {
    interest += balance * 0.02;
  }
  return balance += interest;
}