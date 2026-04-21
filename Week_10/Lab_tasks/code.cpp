#include <iostream>
using namespace std;

int main()
{
  int n;

  cout << "Enter no. of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter profits (+ve) and loss (-ve): ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int closeZero = arr[0] + arr[1];

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {

      if ((arr[i] + arr[j] < closeZero && arr[i] + arr[j] >= 0) ||
          (arr[i] + arr[j] > closeZero && arr[i] + arr[j] <= 0))
      {

        closeZero = arr[i] + arr[j];
      }
    }
  }

  cout << "The closest value to 0 for all individual profits and loss is: "
       << closeZero;

  return 0;
}