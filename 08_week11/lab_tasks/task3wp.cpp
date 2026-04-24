#include <iostream>
using namespace std;

void printToyotaBlue(int array2D[][5]);
int totalRed(int array2D[][5]);
int totalNissan(int array2D[][5]);
int converter(int array2D[][5], string color);
void printCars(int array2D[][5], int rowSize);

int main()
{
  int rowSize = 5;
  int carData[][5] = {
      {10, 7, 12, 10, 4},
      {18, 11, 15, 17, 2},
      {23, 19, 12, 16, 14},
      {7, 12, 16, 0, 2},
      {3, 5, 6, 2, 1}};

  printToyotaBlue(carData);
  totalRed(carData);
  totalNissan(carData);
  converter(carData, "Blue");
  printCars(carData, rowSize);
}

void printToyotaBlue(int array2D[][5])
{
  cout << array2D[1][3];
}
int totalRed(int array2D[][5])
{
  int redCars = 0;
  for (int i = 0; i < 5; i++)
  {
    redCars += array2D[i][0];
  }
  return redCars;
}
int totalNissan(int array2D[][5])
{
  int nissanCars = 0;
  for (int i = 0; i < 5; i++)
  {
    nissanCars += array2D[2][i];
  }
  return nissanCars;
}
int converter(int array2D[][5], string color)
{
  int cars = 0;
  for (int i = 0; i < 5; i++)
  {
    if (color == "Red")
    {
      cars += array2D[i][0];
    }
    else if (color == "Black")
    {
      cars += array2D[i][1];
    }
    else if (color == "Brown")
    {
      cars += array2D[i][2];
    }
    else if (color == "Blue")
    {
      cars += array2D[i][3];
    }
    else if (color == "Gray")
    {
      cars += array2D[i][4];
    }
  }
  return cars;
}
void printCars(int array2D[][5], int rowSize)
{
  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << array2D[j][i] << "\t";
    }
    cout << endl;
  }
}