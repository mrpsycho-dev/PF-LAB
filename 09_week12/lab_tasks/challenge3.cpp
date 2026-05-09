#include <iostream>
using namespace std;

int main()
{
  int size;

  cout << "Enter size of array: ";
  cin >> size;
  int *arr = new int[size];

  cout << "Enter " << size << " elements:\n";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int *start = arr;
  int *end = arr + size - 1;

  while (start < end)
  {
    int temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }

  cout << "Reversed array:\n";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }

  // Free dynamically allocated memory
  delete[] arr;

  return 0;
}