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

// --- Menus ---
void showMainMenu();
void showAdminMenu();
void showTechMenu();
void exitScreen();

// --- Auth ---
bool adminLogin();
bool techLogin(int &loggedIdx);

// --- Admin Functions ---
void addEquipment();
void viewAllEquipment();
void searchEquipment();
void updateEquipment();
void deleteEquipment();
void viewBorrowRecords();
void sortEquipment();
void viewByCategory();
void manageTechnicians();
void viewHistory();

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

////////////////////////////////////////////////////////////////
// MENU DISPLAY FUNCTIONS
////////////////////////////////////////////////////////////////

void showMainMenu()
{
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |         LAB EQUIPMENT MANAGEMENT SYSTEM               |\n";
  cout << "  |                      L E M S                          |\n";
  cout << "  |=======================================================|\n";
  cout << "  |   [1]   Admin Login                                   |\n";
  cout << "  |   [2]   Lab Technician Login                          |\n";
  cout << "  |   [3]   Exit                                          |\n";
  cout << "  |=======================================================|\n";
  cout << "  Choose option: ";
}

void showAdminMenu()
{
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |                  ADMIN DASHBOARD                      |\n";
  cout << "  |=======================================================|\n";
  cout << "  |   [1]   Add Equipment                                 |\n";
  cout << "  |   [2]   View All Equipment                            |\n";
  cout << "  |   [3]   Search Equipment                              |\n";
  cout << "  |   [4]   Update Equipment                              |\n";
  cout << "  |   [5]   Delete Equipment                              |\n";
  cout << "  |   [6]   View Borrowing Records                        |\n";
  cout << "  |   [7]   Sort Equipment                                |\n";
  cout << "  |   [8]   View Equipment by Category                    |\n";
  cout << "  |   [9]   Manage Technicians                            |\n";
  cout << "  |  [10]   Activity History                              |\n";
  cout << "  |  [11]   Logout                                        |\n";
  cout << "  |=======================================================|\n";
  cout << "  Choose option: ";
}

void showTechMenu()
{
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |             LAB TECHNICIAN DASHBOARD                  |\n";
  cout << "  |=======================================================|\n";
  cout << "  |   [1]   View Available Equipment                      |\n";
  cout << "  |   [2]   Search Equipment                              |\n";
  cout << "  |   [3]   Borrow Equipment                              |\n";
  cout << "  |   [4]   Return Equipment                              |\n";
  cout << "  |   [5]   My Issued Records                             |\n";
  cout << "  |   [6]   View Active Borrowings                        |\n";
  cout << "  |   [7]   Equipment Details                             |\n";
  cout << "  |   [8]   Borrowing History                             |\n";
  cout << "  |   [9]   Logout                                        |\n";
  cout << "  |=======================================================|\n";
  cout << "  Choose option: ";
}

void exitScreen()
{
  clearScreen();
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |      Thank you for using LEMS!                        |\n";
  cout << "  |      Lab Equipment Management System                  |\n";
  cout << "  |=======================================================|\n";
}

////////////////////////////////////////////////////////////////
// AUTH FUNCTIONS
////////////////////////////////////////////////////////////////

bool adminLogin()
{
  for (int i = 0; i < 3; i++)
  {
    clearScreen();
    cout << "\n  ADMIN LOGIN - Attempt " << i + 1 << " of 3\n\n";

    string username, password;
    cout << "  Username : ";
    cin >> username;
    cout << "  Password : ";
    cin >> password;

    if (username == "admin" && password == "123")
    {
      cout << "\n  Login Successful!\n";
      pause();
      return true;
    }
    else
    {
      cout << "\n  Invalid credentials!\n";
      pause();
    }
  }
  cout << "\n  Too many failed attempts. Access denied.\n";
  pause();
  return false;
}

bool techLogin(int &loggedIdx)
{
  for (int i = 0; i < 3; i++)
  {
    clearScreen();
    cout << "\n  TECHNICIAN LOGIN - Attempt " << i + 1 << " of 3\n\n";

    string username, password;
    cout << "  Username : ";
    cin >> username;
    cout << "  Password : ";
    cin >> password;

    for (int j = 0; j < techCount; j++)
    {
      if (techUsername[j] == username && password == "123")
      {
        loggedIdx = j;
        cout << "\n  Welcome, " << techName[j] << "!\n";
        pause();
        return true;
      }
    }

    cout << "\n  Invalid credentials!\n";
    pause();
  }
  cout << "\n  Too many failed attempts. Access denied.\n";
  pause();
  return false;
}

////////////////////////////////////////////////////////////////
// ADMIN FUNCTIONS
////////////////////////////////////////////////////////////////

void addEquipment()
{
  clearScreen();
  cout << "\n  ADD NEW EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";

  cout << "  Name                              : ";
  cin >> equipmentName[equipmentCount];
  cout << "  Category (Electronics/Chemistry/  \n";
  cout << "            Physics/Biology)        : ";
  cin >> equipmentCat[equipmentCount];
  cout << "  Quantity                          : ";
  cin >> equipmentQty[equipmentCount];
  equipmentAvail[equipmentCount] = equipmentQty[equipmentCount];
  cout << "  Condition (Good/Fair/Poor)        : ";
  cin >> equipmentCond[equipmentCount];
  cout << "  Price (PKR)                       : ";
  cin >> equipmentPrice[equipmentCount];

  equipmentId[equipmentCount] = nextEquipId++;
  addHistory("Added", equipmentName[equipmentCount], "Admin");
  equipmentCount++;

  cout << "\n  Equipment added successfully!\n";
}

void viewAllEquipment()
{
  clearScreen();
  cout << "\n  ALL EQUIPMENT\n";
  cout << "  " << string(75, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(14) << left << "Category"
       << setw(6) << left << "Qty"
       << setw(7) << left << "Avail"
       << setw(10) << left << "Condition"
       << setw(12) << left << "Price(PKR)"
       << "\n";
  cout << "  " << string(75, '-') << "\n";

  for (int i = 0; i < equipmentCount; i++)
  {
    cout << "  "
         << setw(4) << left << equipmentId[i]
         << setw(16) << left << equipmentName[i]
         << setw(14) << left << equipmentCat[i]
         << setw(6) << left << equipmentQty[i]
         << setw(7) << left << equipmentAvail[i]
         << setw(10) << left << equipmentCond[i]
         << setw(12) << left << equipmentPrice[i]
         << "\n";
  }
}

void searchEquipment()
{
  clearScreen();
  cout << "\n  SEARCH EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter name: ";
  string searchName;
  cin >> searchName;

  bool found = false;
  cout << "\n  " << string(65, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(14) << left << "Category"
       << setw(7) << left << "Avail"
       << setw(10) << left << "Condition"
       << setw(12) << left << "Price(PKR)"
       << "\n";
  cout << "  " << string(65, '-') << "\n";

  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentName[i] == searchName)
    {
      cout << "  "
           << setw(4) << left << equipmentId[i]
           << setw(16) << left << equipmentName[i]
           << setw(14) << left << equipmentCat[i]
           << setw(7) << left << equipmentAvail[i]
           << setw(10) << left << equipmentCond[i]
           << setw(12) << left << equipmentPrice[i]
           << "\n";
      found = true;
    }
  }
  if (!found)
    cout << "\n  No equipment found with that name!\n";
}

void updateEquipment()
{
  clearScreen();
  cout << "\n  UPDATE EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter equipment ID to update: ";
  int updateId;
  cin >> updateId;

  bool found = false;
  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentId[i] == updateId)
    {
      found = true;
      cout << "\n  Current Record:\n";
      cout << "  Name      : " << equipmentName[i] << "\n";
      cout << "  Category  : " << equipmentCat[i] << "\n";
      cout << "  Quantity  : " << equipmentQty[i] << "\n";
      cout << "  Condition : " << equipmentCond[i] << "\n";
      cout << "  Price     : " << equipmentPrice[i] << "\n";

      cout << "\n  Enter New Details:\n";
      cout << "  Name      : ";
      cin >> equipmentName[i];
      cout << "  Category  : ";
      cin >> equipmentCat[i];

      int oldQty = equipmentQty[i];
      cout << "  Quantity  : ";
      cin >> equipmentQty[i];
      int diff = equipmentQty[i] - oldQty;
      equipmentAvail[i] += diff;
      if (equipmentAvail[i] < 0)
        equipmentAvail[i] = 0;

      cout << "  Condition : ";
      cin >> equipmentCond[i];
      cout << "  Price     : ";
      cin >> equipmentPrice[i];

      addHistory("Updated", equipmentName[i], "Admin");
      cout << "\n  Equipment updated successfully!\n";
      break;
    }
  }
  if (!found)
    cout << "\n  Equipment ID not found!\n";
}
