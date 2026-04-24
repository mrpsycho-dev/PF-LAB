#include <iostream>
using namespace std;

int myFunction(int n);
int main()
{
  int number, result;
  cout << "enter number: ";
  cin >> number;
  result = myFunction(number);
}
int myFunction(int n)
{
  int total = n * 5;
  return total;
}