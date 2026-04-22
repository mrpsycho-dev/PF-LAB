#include <iostream>
using namespace std;

float pyramidVolume(float l, float w, float h, string unit);
int main()
{
  float l, w, h;
  cout << "Enter length,width,height: ";
  cin >> l >> w >> h;
  string unit;
  cout << "Enter output unit(millimeters,centimeters, meters, kilometers): ";
  cin >> unit;
  cout << pyramidVolume(l, w, h, unit) << " cubic " << unit;
}
float pyramidVolume(float l, float w, float h, string unit)
{
  if (unit == "millimeters")
  {
    l = l * 1000;
    w = w * 1000;
    h = h * 1000;
  }
  else if (unit == "centimeters")
  {
    l = l * 100;
    w = w * 100;
    h = h * 100;
  }
  else if (unit == "kilometers")
  {
    l = l / 1000;
    w = w / 1000;
    h = h / 1000;
  }

  float volume = (l * w * h) / 3;
  return volume;
}