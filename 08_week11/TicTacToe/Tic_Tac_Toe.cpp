#include <iostream>
using namespace std;

char board[9];

void printBoard()
{
  cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
  cout << "---------" << endl;
  cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
  cout << "---------" << endl;
  cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool checkWin(char p)
{
  // winning Patterns 3 horizontal, 3 vertical, 2 diagonal
  int lines[8][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

  for (int i = 0; i < 8; i++)
  {
    if (board[lines[i][0]] == p && board[lines[i][1]] == p && board[lines[i][2]] == p)
      return true;
  }

  return false;
}

bool boardFull()
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == ' ')
      return false;
  }
  return true;
}

int main()
{
  for (int i = 0; i < 9; i++)
  {
    board[i] = ' ';
  }

  char currentPlayer = 'X';
  int move;

  system("cls");
  cout << R"(
  Tic Tac Toe!
  Enter a number 1-9 to place your mark
  
  1 | 2 | 3
  ---------
  4 | 5 | 6
  ---------
  7 | 8 | 9
)";

  while (true)
  {
    printBoard();
    cout << "Player " << currentPlayer << " enter move: ";
    cin >> move;

    if (move < 1 || move > 9)
    {
      system("cls");
      cout << "Invalid move, try again" << endl
           << endl;
      continue;
    }

    if (board[move - 1] != ' ')
    {
      system("cls");
      cout << "That spot is taken, try again" << endl
           << endl;
      continue;
    }

    board[move - 1] = currentPlayer;

    if (checkWin(currentPlayer))
    {
      system("cls");
      printBoard();
      cout << "Player " << currentPlayer << " wins!" << endl;
      break;
    }

    if (boardFull())
    {
      system("cls");
      printBoard();
      cout << "Its a draw!" << endl;
      break;
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // ternary operator:)
    system("cls");
  }

  return 0;
}