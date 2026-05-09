#include <iostream>
using namespace std;

void modifyWithPointer(int *p, int *q)
{
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

void modifyWithReference(int &r, int &s)
{
  int temp = r;
  r = s;
  s = temp;
}

int main()
{
  int a = 10, b = 20;
  int c = 10, d = 20;

  modifyWithPointer(&a, &b);
  modifyWithReference(c, d);

  cout << a << endl
       << b << endl
       << c << endl
       << d << endl;
  return 0;
}
