#include <iostream>
using namespace std;

bool identityMatrix(int arrData[3][3]);
int main()
{
  int arrData[3][3];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Enter element at position: [" << i << "][" << j << "]";
      cin >> arrData[i][j];
    }
  }
  if (identityMatrix(arrData))
  {
    cout << "The matrix is an identity Matrix.";
  }
  else
  {
    cout << "The matrix is not an identity Matrix.";
  }
}
bool identityMatrix(int arrData[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arrData[i][j] == arrData[j][i])
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
}