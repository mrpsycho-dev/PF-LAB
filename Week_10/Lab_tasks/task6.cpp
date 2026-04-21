#include <iostream>
using namespace std;

void add(int n1, int n2);

int main()
{
  int n1, n2;
  cout << "enter number 1: ";
  cin >> n1;
  cout << "enter number 2: ";
  cin >> n2;
  return 0;
}

void add(int n1, int n2)
{
  cout << "Sum: " << n1 + n2;
}