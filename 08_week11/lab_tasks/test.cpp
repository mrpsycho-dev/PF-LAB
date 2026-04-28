#include <iostream>
using namespace std;

void largestColumnFirst(int arr[][5], int rowSize);
void printMatrix(int arr[][5], int rowSize);

int main()
{
  int rowSize;
  cout << "Enter row size: ";
  cin >> rowSize;

  int arr[rowSize][5];

  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << "Enter element [" << i << "][" << j << "]: ";
      cin >> arr[i][j];
    }
  }

  cout << "Original Matrix:\n";
  printMatrix(arr, rowSize);

  largestColumnFirst(arr, rowSize);

  cout << "\nAfter swapping largest column with first:\n";
  printMatrix(arr, rowSize);
}

void largestColumnFirst(int arr[][5], int rowSize)
{
  int maxSum = 0;
  int maxColIndex = 0;

  for (int i = 0; i < rowSize; i++)
  {
    maxSum += arr[i][0];
  }

  for (int j = 0; j < 5; j++)
  {
    int sum = 0;
    for (int i = 0; i < rowSize; i++)
    {
      sum += arr[i][j];
    }
    if (sum > maxSum)
    {
      maxSum = sum;
      maxColIndex = j;
    }
  }

  for (int i = 0; i < rowSize; i++)
  {
    swap(arr[i][maxColIndex], arr[i][0]);
  }
}
void printMatrix(int arr[][5], int rowSize)
{
  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
}