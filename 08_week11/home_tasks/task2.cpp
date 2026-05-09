#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int rows = 25;
const int cols = 60;

char board[rows][cols];

////////////////////////////////////////////////////////////////
// PLAYER
////////////////////////////////////////////////////////////////
int playerRow = 22;
int playerCol = 28;

int playerLives = 3;
int playerHealth = 100;
int score = 0;
int level = 1;

////////////////////////////////////////////////////////////////
// ENEMY HEALTH
////////////////////////////////////////////////////////////////
int enemyXHealth = 20;
int enemyEHealth = 30;
int enemyTHealth = 50;

////////////////////////////////////////////////////////////////
// INITIALIZE BOARD
////////////////////////////////////////////////////////////////
void initializeBoard()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
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

  ////////////////////////////////////////////////////////////////
  // ENEMIES
  ////////////////////////////////////////////////////////////////
  board[3][10] = 'x';
  board[5][30] = 'e';
  board[7][50] = 't';

  ////////////////////////////////////////////////////////////////
  // PLAYER
  ////////////////////////////////////////////////////////////////
  board[playerRow][playerCol] = 'P';
}

////////////////////////////////////////////////////////////////
// PRINT BOARD
////////////////////////////////////////////////////////////////
void printBoard()
{
  cout << "Score  : " << score << endl;
  cout << "Lives  : " << playerLives << endl;
  cout << "Health : " << playerHealth << endl;
  cout << "Level  : " << level << endl;
  cout << endl;

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
// PLAYER MOVEMENT
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

void movePlayerRight()
{
  if (board[playerRow][playerCol + 1] == ' ')
  {
    board[playerRow][playerCol] = ' ';
    playerCol++;
    board[playerRow][playerCol] = 'P';
  }
}

void movePlayerUp()
{
  if (board[playerRow - 1][playerCol] == ' ')
  {
    board[playerRow][playerCol] = ' ';
    playerRow--;
    board[playerRow][playerCol] = 'P';
  }
}

void movePlayerDown()
{
  if (board[playerRow + 1][playerCol] == ' ')
  {
    board[playerRow][playerCol] = ' ';
    playerRow++;
    board[playerRow][playerCol] = 'P';
  }
}

////////////////////////////////////////////////////////////////
// PLAYER FIRE
////////////////////////////////////////////////////////////////
void firePlayer()
{
  if (board[playerRow - 1][playerCol] == ' ')
  {
    board[playerRow - 1][playerCol] = '.';
  }
}

////////////////////////////////////////////////////////////////
// MOVE PLAYER BULLETS
////////////////////////////////////////////////////////////////
void movePlayerBullets()
{
  for (int r = 1; r < rows - 1; r++)
  {
    for (int c = 1; c < cols - 1; c++)
    {
      if (board[r][c] == '.')
      {
        ////////////////////////////////////////////////////////
        // HIT x
        ////////////////////////////////////////////////////////
        if (board[r - 1][c] == 'x')
        {
          enemyXHealth -= 10;
          board[r][c] = ' ';

          if (enemyXHealth <= 0)
          {
            board[r - 1][c] = ' ';
            score += 10;
          }
        }

        ////////////////////////////////////////////////////////
        // HIT e
        ////////////////////////////////////////////////////////
        else if (board[r - 1][c] == 'e')
        {
          enemyEHealth -= 10;
          board[r][c] = ' ';

          if (enemyEHealth <= 0)
          {
            board[r - 1][c] = ' ';
            score += 20;
          }
        }

        ////////////////////////////////////////////////////////
        // HIT t
        ////////////////////////////////////////////////////////
        else if (board[r - 1][c] == 't')
        {
          enemyTHealth -= 10;
          board[r][c] = ' ';

          if (enemyTHealth <= 0)
          {
            board[r - 1][c] = ' ';
            score += 50;
          }
        }

        ////////////////////////////////////////////////////////
        // MOVE BULLET
        ////////////////////////////////////////////////////////
        else if (board[r - 1][c] == ' ')
        {
          board[r - 1][c] = '.';
          board[r][c] = ' ';
        }

        ////////////////////////////////////////////////////////
        // REMOVE BULLET
        ////////////////////////////////////////////////////////
        else
        {
          board[r][c] = ' ';
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// ENEMY MOVEMENT
////////////////////////////////////////////////////////////////
int enemyDirection = 1;

void moveEnemyX()
{
  for (int r = 1; r < rows - 1; r++)
  {
    for (int c = 1; c < cols - 1; c++)
    {
      if (board[r][c] == 'x')
      {
        if (enemyDirection == 1)
        {
          if (board[r][c + 1] == ' ')
          {
            board[r][c + 1] = 'x';
            board[r][c] = ' ';
          }
          else
          {
            enemyDirection = -1;
          }
        }
        else
        {
          if (board[r][c - 1] == ' ')
          {
            board[r][c - 1] = 'x';
            board[r][c] = ' ';
          }
          else
          {
            enemyDirection = 1;
          }
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// ENEMY e MOVEMENT (VERTICAL)
////////////////////////////////////////////////////////////////
int enemyVerticalDirection = 1;

void moveEnemyE()
{
  for (int r = 1; r < rows - 1; r++)
  {
    for (int c = 1; c < cols - 1; c++)
    {
      if (board[r][c] == 'e')
      {
        if (enemyVerticalDirection == 1)
        {
          if (board[r + 1][c] == ' ')
          {
            board[r + 1][c] = 'e';
            board[r][c] = ' ';
          }
          else
          {
            enemyVerticalDirection = -1;
          }
        }
        else
        {
          if (board[r - 1][c] == ' ')
          {
            board[r - 1][c] = 'e';
            board[r][c] = ' ';
          }
          else
          {
            enemyVerticalDirection = 1;
          }
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// ENEMY FIRE
////////////////////////////////////////////////////////////////
void fireEnemy()
{
  for (int r = 1; r < rows - 1; r++)
  {
    for (int c = 1; c < cols - 1; c++)
    {
      if (board[r][c] == 't')
      {
        if (board[r + 1][c] == ' ')
        {
          board[r + 1][c] = 'o';
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// MOVE ENEMY BULLETS
////////////////////////////////////////////////////////////////
void moveEnemyBullets()
{
  for (int r = rows - 2; r >= 1; r--)
  {
    for (int c = cols - 2; c >= 1; c--)
    {
      if (board[r][c] == 'o')
      {
        ////////////////////////////////////////////////////////
        // HIT PLAYER
        ////////////////////////////////////////////////////////
        if (board[r + 1][c] == 'P')
        {
          board[r][c] = ' ';

          playerHealth -= 20;

          if (playerHealth <= 0)
          {
            playerLives--;
            playerHealth = 100;
          }
        }

        ////////////////////////////////////////////////////////
        // MOVE BULLET
        ////////////////////////////////////////////////////////
        else if (board[r + 1][c] == ' ')
        {
          board[r + 1][c] = 'o';
          board[r][c] = ' ';
        }

        ////////////////////////////////////////////////////////
        // REMOVE BULLET
        ////////////////////////////////////////////////////////
        else
        {
          board[r][c] = ' ';
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////
// LEVEL SYSTEM
////////////////////////////////////////////////////////////////
void changeLevel()
{
  if (score >= 50)
  {
    level = 2;

    for (int c = 15; c < 45; c++)
    {
      board[12][c] = '#';
    }
  }

  if (score >= 100)
  {
    level = 3;

    for (int r = 5; r < 20; r++)
    {
      board[r][20] = '#';
      board[r][40] = '#';
    }
  }
}

////////////////////////////////////////////////////////////////
// GAME OVER
////////////////////////////////////////////////////////////////
bool gameOver()
{
  if (playerLives <= 0)
  {
    return true;
  }

  return false;
}

////////////////////////////////////////////////////////////////
// MAIN
////////////////////////////////////////////////////////////////
int main()
{
  initializeBoard();

  int timer = 0;

  while (true)
  {
    system("cls");

    printBoard();

    ////////////////////////////////////////////////////////////
    // GAME OVER
    ////////////////////////////////////////////////////////////
    if (gameOver())
    {
      cout << endl;
      cout << "GAME OVER" << endl;
      break;
    }

    ////////////////////////////////////////////////////////////
    // INPUT
    ////////////////////////////////////////////////////////////
    if (GetAsyncKeyState(VK_LEFT))
    {
      movePlayerLeft();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
      movePlayerRight();
    }

    if (GetAsyncKeyState(VK_UP))
    {
      movePlayerUp();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
      movePlayerDown();
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
      firePlayer();
    }

    ////////////////////////////////////////////////////////////
    // MOVEMENTS
    ////////////////////////////////////////////////////////////
    movePlayerBullets();

    if (timer % 3 == 0)
    {
      moveEnemyX();
    }

    if (timer % 4 == 0)
    {
      moveEnemyE();
    }

    if (timer % 6 == 0)
    {
      fireEnemy();
    }

    moveEnemyBullets();

    changeLevel();

    timer++;

    Sleep(100);
  }

  return 0;
}