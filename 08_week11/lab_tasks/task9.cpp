#include <iostream>
using namespace std;

int countIdenticalRows(int arr[][3], int size);

int main()
{
  int size;
  cout << "Enter row size: ";
  cin >> size;

  int arr[size][3];

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter element [" << i << "][" << j << "]: ";
      cin >> arr[i][j];
    }
  }
  cout << countIdenticalRows(arr, size);
}
int countIdenticalRows(int arr[][3], int size)
{
  int count = 0;
  bool identical = false;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (arr[i][j] == arr[i][k])
        {
          identical = true;
          break;
        }
      }
      if (identical)
      {
        count++;
      }
    }
  }
  return count;
}
