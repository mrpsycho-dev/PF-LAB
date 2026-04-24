#include <iostream>
using namespace std;

void printCars(int card[][5], int rowSize);
int main()
{
  int rowSize = 5;
  int carData[][5] = {
      {10, 7, 12, 10, 4},
      {18, 11, 15, 17, 2},
      {23, 19, 12, 16, 14},
      {7, 12, 16, 0, 2},
      {3, 5, 6, 2, 1}};

  printCars(carData, rowSize);
}

void printCars(int array2D[][5], int rowSize)
{
  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << array2D[i][j] << "\t";
    }
    cout << endl;
  }
}