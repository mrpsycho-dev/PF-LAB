#include <iostream>
using namespace std;
void displayWorld(char arr[5][5]);
bool setGravityStatus(bool status);
void timeTick(int time, char arr[5][5]);
bool gravity = false;
bool isBlackHole = true;

int main()
{
  char objects[5][5] = {
      {'-', '#', '#', '-', '#'},
      {'#', '-', '-', '#', '-'},
      {'-', '#', '-', '-', '-'},
      {'#', '-', '#', '-', '#'},
      {'#', '-', '-', '-', '-'}};

  displayWorld(objects);
  setGravityStatus(true);
  isBlackHole = true;
  timeTick(1, objects);
  displayWorld(objects);
}

void displayWorld(char arr[5][5])
{
  cout << "Y O U R    W O R L D: \n";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
}

bool setGravityStatus(bool status)
{
  gravity = status;
  return gravity;
}

void timeTick(int time, char arr[5][5])
{
  if (!gravity)
    return;

  if (isBlackHole)
  {
    // It is because after every 5 timeTicks, world returns to its original state. So:
    int shifts = time % 5;

    for (int s = 0; s < shifts; s++)
    {
      // Save the last row
      char lastRow[5];
      for (int j = 0; j < 5; j++)
        lastRow[j] = arr[4][j];

      for (int i = 4; i >= 1; i--)
        for (int j = 0; j < 5; j++)
          arr[i][j] = arr[i - 1][j];

      // Move the last row to top
      for (int j = 0; j < 5; j++)
        arr[0][j] = lastRow[j];
    }
  }
  else
  {
    for (int t = 0; t < time; t++)
      for (int i = 3; i >= 0; i--)
        for (int j = 0; j < 5; j++)
          if (arr[i][j] == '#' && arr[i + 1][j] == '-')
          {
            arr[i][j] = '-';
            arr[i + 1][j] = '#';
          }
  }
}