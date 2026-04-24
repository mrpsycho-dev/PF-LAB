#include <iostream>
using namespace std;

int printSum(int arrData[][3], int rowSize);
int main()
{
  int rowSize;
  cout << "Enter row size: ";
  cin >> rowSize;
  int arrData[rowSize][3];

  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter element at position: [" << i << "][" << j << "]";
      cin >> arrData[i][j];
    }
  }
  printSum(arrData, rowSize);
}
int printSum(int arrData[][3], int rowSize)
{
  int x = 0;
  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      x += arrData[i][j];
    }
  }
  return x;
}