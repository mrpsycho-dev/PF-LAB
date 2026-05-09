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
  // isBlackHole = true;
  timeTick(3, objects);
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
}
void timeTick(int time, char arr[5][5])
{
  if (!gravity)
  {
    return;
  }

  for (int i = 0; i < time; i++)
  {
    for (int j = 4; j >= 0; j--)
    {
      for (int k = 0; k < 5; k++)
      {
        // if (isBlackHole)
        // {
        //   if (j == 0)
        //   {
        //     arr[j][k] = arr[4][k];
        //   }
        //   else
        //   {
        //     arr[j][k] = arr[j - 1][k];
        //   }
        // }
        // else
        if (j <= 3 && arr[j][k] == '#' && arr[j + 1][k] == '-')
        {
          arr[j][k] = '-';
          arr[j + 1][k] = '#';
        }
      }
    }
  }
}