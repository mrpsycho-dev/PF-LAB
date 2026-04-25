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

  // Find column with largest sum
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

  // Swap columns
  for (int i = 0; i < rowSize; i++)
  {
    int temp = arr[i][0];
    arr[i][0] = arr[i][maxColIndex];
    arr[i][maxColIndex] = temp;
  }
}

void printMatrix(int arr[][5], int rowSize)
{
  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}