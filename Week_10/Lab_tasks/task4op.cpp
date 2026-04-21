#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float n1, n2;
  cout << "Enter distance from tree(in feet): ";
  cin >> n1;
  cout << "Enter angle of elevation(degrees): ";
  cin >> n2;
  cout << "Height: " << n1 * (tan(n2 / 57.2958));
}