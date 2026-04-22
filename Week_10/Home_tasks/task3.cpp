#include <iostream>
using namespace std;

float taxCalculator(char type, float price);
int main()
{
  char type;
  float price;
  cout << "enter vehicle type: ";
  cin >> type;
  cout << "enter price of vehicle: ";
  cin >> price;
  cout << "The final price of vehicle is: " << price + taxCalculator(type, price);
}
float taxCalculator(char type, float price)
{
  float taxRate;
  if (type == 'M' || 'm')
  {
    taxRate = 6 / 100;
  }
  else if (type == 'E' || 'e')
  {
    taxRate = 8 / 100;
  }
  else if (type == 'S' || 's')
  {
    taxRate = 10 / 100;
  }
  else if (type == 'V' || 'v')
  {
    taxRate = 12 / 100;
  }
  else if (type == 'T' || 't')
  {
    taxRate = 15 / 100;
  }
  return price * taxRate;
}