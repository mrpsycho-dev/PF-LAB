#include <iostream>
using namespace std;

void displayWorld(arr[5][5]);
bool setGravityStatus(bool status);
int timeTick(int time);

int main()
{
  char objects[5][5] = {
      {'-', '#', '#', '-', '#'},
      {'#', '-', '-', '#', '-'},
      {'-', '#', '-', '-', '-'},
      {'#', '-', '#', '-', '#'},
      {'#', '-', '-', '-', '-'}};
  bool gravity = false;

  // displayWorld();
  // setGravityStatus(true);
  // timeTick(3);
  // displayWorld();
}

void displayWorld(arr[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j] << "\t";
    }
  }
}
bool setGravityStatus(bool status) {}
int timeTick(int time) {}