#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

////////////////////////////////////////////////////////////////
// CONSTANTS
////////////////////////////////////////////////////////////////
const int MAX = 200;
const int MAX_TECH = 10;

////////////////////////////////////////////////////////////////
// GLOBAL DATA - EQUIPMENT
////////////////////////////////////////////////////////////////
int equipmentCount = 5;
int equipmentId[MAX] = {1, 2, 3, 4, 5};
string equipmentName[MAX] = {"Microscope", "Oscilloscope", "BunsenBurner", "Voltmeter", "Centrifuge"};
string equipmentCat[MAX] = {"Biology", "Electronics", "Chemistry", "Electronics", "Biology"};
int equipmentQty[MAX] = {5, 3, 8, 6, 2};
int equipmentAvail[MAX] = {5, 3, 8, 6, 2};
string equipmentCond[MAX] = {"Good", "Good", "Fair", "Good", "Fair"};
float equipmentPrice[MAX] = {15000, 25000, 2000, 5000, 50000};
int nextEquipId = 6;

////////////////////////////////////////////////////////////////
// GLOBAL DATA - BORROW
////////////////////////////////////////////////////////////////
int borrowCount = 0;
int borrowId[MAX];
string borrowEquipName[MAX];
string borrowerName[MAX];
string borrowerRoll[MAX];
string borrowDate[MAX];
string returnDate[MAX];
string borrowStatus[MAX];
string borrowIssuedBy[MAX];
int nextBorrowId = 1;

////////////////////////////////////////////////////////////////
// GLOBAL DATA - HISTORY
////////////////////////////////////////////////////////////////
int historyCount = 0;
string historyAction[MAX];
string historyItem[MAX];
string historyBy[MAX];

////////////////////////////////////////////////////////////////
// GLOBAL DATA - TECHNICIANS
////////////////////////////////////////////////////////////////
int techCount = 2;
string techUsername[MAX_TECH] = {"tech1", "tech2"};
string techName[MAX_TECH] = {"Dr.Sara", "Mr.Hamza"};

////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////

// --- Utility ---
void addHistory(string action, string item, string by);
void pause();
void clearScreen();

int main() {}

////////////////////////////////////////////////////////////////
// UTILITY FUNCTIONS
////////////////////////////////////////////////////////////////

void addHistory(string action, string item, string by)
{
  historyAction[historyCount] = action;
  historyItem[historyCount] = item;
  historyBy[historyCount] = by;
  historyCount++;
}

void pause()
{
  cout << "\n  Press any key to continue...";
  getch();
}

void clearScreen()
{
  system("cls");
}
