#include <iostream>
using namespace std;

void add(int num1, int num2);

int main()
{
  int num1, num2;
  cin >> num1 >> num2;
  add(num1, num2);
}

void add(int num1, int num2)
{
  cout << "Sum: " << num1 + num2;
}