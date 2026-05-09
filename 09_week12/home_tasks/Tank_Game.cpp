#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

///////////////////////////////////////////////
// Supporting Functions (declared first)
///////////////////////////////////////////////

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

///////////////////////////////////////////////
// Step 01: Print Maze and Characters
///////////////////////////////////////////////

void printMaze()
{
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
}

// Player Character
char box = (char)219;
char tank1[6] = {box, box, box, '-', '-', '>'};
char tank2[6] = {'0', ' ', '0', ' ', ' ', ' '};

// Enemy Character
char enemy1[6] = {' ', ' ', ' ', '-', '-', '-'};
char enemy2[6] = {'<', '=', '=', '(', '-', ')'};
char enemy3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char enemy4[6] = {' ', ' ', ' ', '*', '*', '*'};

// Player Coordinates
int tankX = 5;
int tankY = 5;

// Enemy Coordinates
int enemyX = 30;
int enemyY = 10;

// Enemy movement direction
string enemyDirection = "Up";

// Score and timer
int score = 0;
int timer = 0;

// Forward declarations
void eraseTank();
void eraseEnemy();
void printTank();
void printEnemy();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);

void printTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0; index < 6; index++)
    {
        cout << tank1[index];
    }
    gotoxy(tankX, tankY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << tank2[index];
    }
}

void printEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy1[index];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy2[index];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy3[index];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy4[index];
    }
}

///////////////////////////////////////////////
// Step 02: Character Movement
///////////////////////////////////////////////

void eraseTank()
{
    gotoxy(tankX, tankY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void moveTankLeft()
{
    char next = getCharAtxy(tankX - 1, tankY);
    if (next == ' ')
    {
        eraseTank();
        tankX = tankX - 1;
        printTank();
    }
}

void moveTankRight()
{
    char next = getCharAtxy(tankX + 6, tankY);
    if (next == ' ')
    {
        eraseTank();
        tankX = tankX + 1;
        printTank();
    }
}

void moveTankUp()
{
    char next = getCharAtxy(tankX, tankY - 1);
    if (next == ' ')
    {
        eraseTank();
        tankY = tankY - 1;
        printTank();
    }
}

void moveTankDown()
{
    char next = getCharAtxy(tankX, tankY + 2);
    if (next == ' ')
    {
        eraseTank();
        tankY = tankY + 1;
        printTank();
    }
}

void moveEnemy()
{
    if (enemyDirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY--;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Down";
        }
    }
    if (enemyDirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY++;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Up";
        }
    }
}

///////////////////////////////////////////////
// Step 03: Firing/Shooting
///////////////////////////////////////////////

// Player Bullets
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}

void generateBullet()
{
    if (bulletCount < 100)
    {
        bulletX[bulletCount] = tankX + 7;
        bulletY[bulletCount] = tankY;
        isBulletActive[bulletCount] = true;
        gotoxy(tankX + 7, tankY);
        cout << ".";
        bulletCount++;
    }
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}

/////////////////////////////////////////////
// Step 04: Collision Detection & Scoring
/////////////////////////////////////////////

void addScore()
{
    score++;
}

void printScore()
{
    gotoxy(45, 8); // FIX: moved inside maze boundary (was outside the 50-char wide maze)
    cout << "Score: " << score;
}

void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3))
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
                addScore();
            }
            if (enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
                addScore();
            }
        }
    }
}

////////////////////////////////////////
// Main Function
////////////////////////////////////////

int main()
{
    system("cls");
    printMaze();
    printTank();
    printEnemy();
    while (true)
    {
        printScore();
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveTankLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveTankRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveTankUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveTankDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }

        if (timer == 3)
        {
            moveEnemy();
            timer = 0;
        }
        moveBullet();
        bulletCollisionWithEnemy();
        timer++;
        Sleep(90);
    }
    return 0;
}