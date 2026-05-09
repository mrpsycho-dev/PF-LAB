#include <iostream>
using namespace std;

const int rows = 25;
const int cols = 60;

char board[rows][cols];

int playerRow = 21;
int playerCol = 25;

////////////////////////////////////////////////////////////////
// CREATE BOARD
////////////////////////////////////////////////////////////////
void initializeBoard()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      // Borders
      if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
      {
        board[r][c] = '#';
      }
      else
      {
        board[r][c] = ' ';
      }
    }
  }

  // Enemies
  board[3][40] = 'x';
  board[6][17] = 'e';
  board[8][30] = 'x';
  board[10][48] = 'e';
  board[12][7] = 'x';

  // Player
  board[playerRow][playerCol] = 'P';
}

////////////////////////////////////////////////////////////////
// PRINT BOARD
////////////////////////////////////////////////////////////////
void printBoard()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      cout << board[r][c];
    }
    cout << endl;
  }
}

////////////////////////////////////////////////////////////////
// MOVE PLAYER LEFT
////////////////////////////////////////////////////////////////
void movePlayerLeft()
{
  if (board[playerRow][playerCol - 1] == ' ')
  {
    board[playerRow][playerCol] = ' ';
    playerCol--;
    board[playerRow][playerCol] = 'P';
  }
}

////////////////////////////////////////////////////////////////
// MOVE PLAYER RIGHT
////////////////////////////////////////////////////////////////
void movePlayerRight()
{
  if (board[playerRow][playerCol + 1] == ' ')
  {
    board[playerRow][playerCol] = ' ';
    playerCol++;
    board[playerRow][playerCol] = 'P';
  }
}

////////////////////////////////////////////////////////////////
// FIRE
////////////////////////////////////////////////////////////////
void fire()
{
  if (board[playerRow - 1][playerCol] == ' ')
  {
    board[playerRow - 1][playerCol] = '.';
  }
}

////////////////////////////////////////////////////////////////
// MOVE FIRE
////////////////////////////////////////////////////////////////
void moveFire(int timeStep)
{
  if (timeStep % 1 == 0)
  {
    for (int r = 1; r < rows - 1; r++)
    {
      for (int c = 1; c < cols - 1; c++)
      {
        if (board[r][c] == '.')
        {
          // Hit enemy
          if (board[r - 1][c] == 'x' || board[r - 1][c] == 'e')
          {
            board[r][c] = ' ';
            board[r - 1][c] = ' ';
          }

          // Move upward
          else if (board[r - 1][c] == ' ')
          {
            board[r - 1][c] = '.';
            board[r][c] = ' ';
          }

          // Remove at border
          else
          {
            board[r][c] = ' ';
          }
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// MOVE ENEMY
////////////////////////////////////////////////////////////////
void moveEnemy(char object, string direction)
{
  if (direction == "left")
  {
    for (int r = 1; r < rows - 1; r++)
    {
      for (int c = 1; c < cols - 1; c++)
      {
        if (board[r][c] == object)
        {
          if (board[r][c - 1] == ' ')
          {
            board[r][c - 1] = object;
            board[r][c] = ' ';
          }
        }
      }
    }
  }

  else if (direction == "right")
  {
    for (int r = rows - 2; r >= 1; r--)
    {
      for (int c = cols - 2; c >= 1; c--)
      {
        if (board[r][c] == object)
        {
          if (board[r][c + 1] == ' ')
          {
            board[r][c + 1] = object;
            board[r][c] = ' ';
          }
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// MAIN
////////////////////////////////////////////////////////////////
int main()
{
  initializeBoard();

  int option;
  int timeStep = 0;

  while (true)
  {
    system("cls");

    printBoard();

    cout << endl;
    cout << "1. Left" << endl;
    cout << "2. Right" << endl;
    cout << "3. Fire" << endl;
    cout << "4. Move x Left" << endl;
    cout << "5. Move e Right" << endl;
    cout << "0. Exit" << endl;

    cin >> option;

    if (option == 1)
    {
      movePlayerLeft();
    }

    else if (option == 2)
    {
      movePlayerRight();
    }

    else if (option == 3)
    {
      fire();
    }

    else if (option == 4)
    {
      moveEnemy('x', "left");
    }

    else if (option == 5)
    {
      moveEnemy('e', "right");
    }

    else if (option == 0)
    {
      break;
    }

    moveFire(timeStep);

    timeStep++;
  }

  return 0;
}