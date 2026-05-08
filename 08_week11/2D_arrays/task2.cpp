#include <iostream>
using namespace std;

int inputMatrix(int arr[][100], int m, int n);
int matrixSum(int arr[][100], int m, int n);

int main() {}
int inputMatrix(int arr[][100], int m, int n)
{
  cout << "Enter size of rows: ";
  cin >> m;
  cout << "Enter size of columns: ";
  cin >> n;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[m][n];
    }
  }
}
int matrixSum(int arr[][100], int m, int n)
{
  
}