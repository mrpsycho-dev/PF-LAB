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

// --- Shared Functions which are used by Admin and Technician both ---
void viewEquipment(bool availableOnly);
void searchEquipment();
void viewBorrowTable(string title,
                     string filterBy,
                     string filterValue);
void equipmentDetails();

// --- Admin Functions ---
void addEquipment();
void updateEquipment();
void deleteEquipment();
void sortEquipment();
void viewByCategory();
void manageTechnicians();
void viewHistory();

// --- Technician Functions ---
void borrowEquipment(int techIdx);
void returnEquipment(int techIdx);

////////////////////////////////////////////////////////////////
// MAIN FUNCTION
////////////////////////////////////////////////////////////////
int main()
{
  while (true)
  {
    clearScreen();
    showMainMenu();

    int choice;
    cin >> choice;

    ////////////////////////////////////////////////////////////
    // ADMIN SECTION
    ////////////////////////////////////////////////////////////
    if (choice == 1)
    {
      if (adminLogin())
      {
        while (true)
        {
          clearScreen();
          showAdminMenu();

          int c;
          cin >> c;

          if (c == 1)
            addEquipment();
          else if (c == 2)
            viewEquipment(false);
          else if (c == 3)
            searchEquipment();
          else if (c == 4)
            updateEquipment();
          else if (c == 5)
            deleteEquipment();
          else if (c == 6)
            viewBorrowTable("ALL BORROWING RECORDS", "all", "");
          else if (c == 7)
            sortEquipment();
          else if (c == 8)
            viewByCategory();
          else if (c == 9)
            manageTechnicians();
          else if (c == 10)
            equipmentDetails();
          else if (c == 11)
            viewHistory();
          else if (c == 12)
          {
            cout << "\n  Logging out...\n";
            pause();
            break;
          }
          else
            cout << "\n  Invalid option!\n";

          pause();
        }
      }
    }
    ////////////////////////////////////////////////////////////
    // TECHNICIAN SECTION
    ////////////////////////////////////////////////////////////
    else if (choice == 2)
    {
      int loggedIdx = -1;
      if (techLogin(loggedIdx))
      {
        while (true)
        {
          clearScreen();
          cout << "\n  Logged in as: " << techName[loggedIdx] << "\n";
          showTechMenu();

          int c;
          cin >> c;

          if (c == 1)
            viewEquipment(true);
          else if (c == 2)
            searchEquipment();
          else if (c == 3)
            borrowEquipment(loggedIdx);
          else if (c == 4)
            returnEquipment(loggedIdx);
          else if (c == 5)
            viewBorrowTable("MY ISSUED RECORDS",
                            "issuedBy",
                            techName[loggedIdx]);
          else if (c == 6)
            viewBorrowTable("ACTIVE BORROWINGS", "status", "Borrowed");
          else if (c == 7)
            equipmentDetails();
          else if (c == 8)
            viewBorrowTable("BORROWING HISTORY", "all", "");
          else if (c == 9)
          {
            cout << "\n  Logging out...\n";
            pause();
            break;
          }
          else
            cout << "\n  Invalid option!\n";

          pause();
        }
      }
    }
    ////////////////////////////////////////////////////////////
    // EXIT
    ////////////////////////////////////////////////////////////
    else if (choice == 3)
    {
      exitScreen();
      break;
    }
    else
    {
      cout << "\n  Invalid option!\n";
      pause();
    }
  }

  return 0;
}

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
  cout << "  |  [10]   Equipment Details                             |\n";
  cout << "  |  [11]   Activity History                              |\n";
  cout << "  |  [12]   Logout                                        |\n";
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
  cout << "  |=======================================================|\n\n";
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
    cout << "\n  Invalid credentials!\n";
    pause();
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
// SHARED FUNCTIONS
////////////////////////////////////////////////////////////////

// availableOnly = false  ->  Admin  "View All Equipment"       (every item)
// availableOnly = true   ->  Tech   "View Available Equipment" (Equipment availability > 0 only)
void viewEquipment(bool availableOnly)
{
  clearScreen();
  if (availableOnly)
    cout << "\n  AVAILABLE EQUIPMENT\n";
  else
    cout << "\n  ALL EQUIPMENT\n";

  cout << "  " << string(72, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(14) << left << "Category"
       << setw(6) << left << "Qty"
       << setw(7) << left << "Avail"
       << setw(10) << left << "Condition"
       << setw(12) << left << "Price(PKR)"
       << "\n";
  cout << "  " << string(72, '-') << "\n";

  bool anyShown = false;
  for (int i = 0; i < equipmentCount; i++)
  {
    if (availableOnly && equipmentAvail[i] <= 0)
      continue;

    cout << "  "
         << setw(4) << left << equipmentId[i]
         << setw(16) << left << equipmentName[i]
         << setw(14) << left << equipmentCat[i]
         << setw(6) << left << equipmentQty[i]
         << setw(7) << left << equipmentAvail[i]
         << setw(10) << left << equipmentCond[i]
         << setw(12) << left << equipmentPrice[i]
         << "\n";
    anyShown = true;
  }
  if (!anyShown)
    cout << "\n  No equipment to display.\n";
}

// Search Equipments
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

void viewBorrowTable(string title, string filterBy, string filterValue)
{
  clearScreen();
  cout << "\n  " << title << "\n";
  cout << "  " << string(81, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Equipment"
       << setw(14) << left << "Borrower"
       << setw(12) << left << "Roll No."
       << setw(13) << left << "Borrow Date"
       << setw(12) << left << "Due Date"
       << setw(10) << left << "Status"
       << "\n";
  cout << "  " << string(81, '-') << "\n";

  if (borrowCount == 0)
  {
    cout << "\n  No records yet.\n";
    return;
  }

  bool anyShown = false;
  for (int i = 0; i < borrowCount; i++)
  {
    if (filterBy == "status" && borrowStatus[i] != filterValue)
      continue;
    if (filterBy == "issuedBy" && borrowIssuedBy[i] != filterValue)
      continue;

    cout << "  "
         << setw(4) << left << borrowId[i]
         << setw(16) << left << borrowEquipName[i]
         << setw(14) << left << borrowerName[i]
         << setw(12) << left << borrowerRoll[i]
         << setw(13) << left << borrowDate[i]
         << setw(12) << left << returnDate[i]
         << setw(10) << left << borrowStatus[i]
         << "\n";
    anyShown = true;
  }
  if (!anyShown)
    cout << "\n  No matching records found.\n";
}

void equipmentDetails()
{
  clearScreen();
  cout << "\n  EQUIPMENT DETAILS\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter equipment ID: ";
  int detailId;
  cin >> detailId;

  bool found = false;
  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentId[i] == detailId)
    {
      found = true;
      clearScreen();

      if (equipmentCat[i] == "Biology")
      {
        cout << R"(
        ,---.
       (     )
        `---'
       /     \
      |  o   o|        BIOLOGY EQUIPMENT
       \  ---/
        |||||
       /|||||\
      /__|||||__\
)";
      }
      else if (equipmentCat[i] == "Electronics")
      {
        cout << R"(
     _______________
    |    DISPLAY    |
    |  ___________  |
    | |           | |     ELECTRONICS EQUIPMENT
    | |   ~~~~    | |
    | |___________| |
    |  [o] [o] [o]  |
    |_______________|
)";
      }
      else if (equipmentCat[i] == "Chemistry")
      {
        cout << R"(
          | |
          | |
         /   \
        /     \         CHEMISTRY EQUIPMENT
       |       |
    ___| _____ |___
   |   |_______|   |
   |_______________|
    *   *   *   *
)";
      }
      else if (equipmentCat[i] == "Physics")
      {
        cout << R"(
   ________________________
  |                        |
  |   PHYSICS EQUIPMENT    |
  |     O         O        |
  |    /|\       /|\       |
  |   / | \     / | \      |
  |__/__|__\___/__|__\_____|
)";
      }
      else
      {
        cout << "\n  [GENERAL LAB EQUIPMENT]\n";
      }

      cout << "\n";
      cout << "  " << string(35, '-') << "\n";
      cout << "  ID        : " << equipmentId[i] << "\n";
      cout << "  Name      : " << equipmentName[i] << "\n";
      cout << "  Category  : " << equipmentCat[i] << "\n";
      cout << "  Quantity  : " << equipmentQty[i] << "\n";
      cout << "  Available : " << equipmentAvail[i] << "\n";
      cout << "  Condition : " << equipmentCond[i] << "\n";
      cout << "  Price     : PKR " << equipmentPrice[i] << "\n";
      cout << "  " << string(35, '-') << "\n";
      break;
    }
  }
  if (!found)
    cout << "\n  Equipment not found!\n";
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

void deleteEquipment()
{
  clearScreen();
  cout << "\n  DELETE EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter equipment ID to delete: ";
  int deleteId;
  cin >> deleteId;

  bool found = false;
  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentId[i] == deleteId)
    {
      found = true;
      cout << "\n  Equipment : " << equipmentName[i] << "\n";
      cout << "  Confirm delete? (y/n): ";
      char confirm;
      cin >> confirm;

      if (confirm == 'y' || confirm == 'Y')
      {
        string deletedName = equipmentName[i];

        for (int j = i; j < equipmentCount - 1; j++)
        {
          equipmentId[j] = equipmentId[j + 1];
          equipmentName[j] = equipmentName[j + 1];
          equipmentCat[j] = equipmentCat[j + 1];
          equipmentQty[j] = equipmentQty[j + 1];
          equipmentAvail[j] = equipmentAvail[j + 1];
          equipmentCond[j] = equipmentCond[j + 1];
          equipmentPrice[j] = equipmentPrice[j + 1];
        }
        equipmentCount--;
        addHistory("Deleted", deletedName, "Admin");
        cout << "\n  Equipment deleted!\n";
      }
      else
      {
        cout << "\n  Deletion cancelled.\n";
      }
      break;
    }
  }
  if (!found)
    cout << "\n  Equipment ID not found!\n";
}

void sortEquipment()
{
  clearScreen();
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |                  SORT EQUIPMENT                       |\n";
  cout << "  |=======================================================|\n";
  cout << "  |   [1]   Price  - Ascending  (Lowest First)            |\n";
  cout << "  |   [2]   Price  - Descending (Highest First)           |\n";
  cout << "  |   [3]   Name   - A to Z                               |\n";
  cout << "  |   [4]   Name   - Z to A                               |\n";
  cout << "  |=======================================================|\n";
  cout << "  Choose option: ";

  int sortChoice;
  cin >> sortChoice;

  for (int i = 0; i < equipmentCount; i++)
  {
    for (int j = i + 1; j < equipmentCount; j++)
    {
      bool doSwap = false;

      if (sortChoice == 1 && equipmentPrice[i] > equipmentPrice[j])
        doSwap = true;
      if (sortChoice == 2 && equipmentPrice[i] < equipmentPrice[j])
        doSwap = true;
      if (sortChoice == 3 && equipmentName[i] > equipmentName[j])
        doSwap = true;
      if (sortChoice == 4 && equipmentName[i] < equipmentName[j])
        doSwap = true;
    

      if (doSwap)
      {
        int tId = equipmentId[i];
        equipmentId[i] = equipmentId[j];
        equipmentId[j] = tId;
        
        string tName = equipmentName[i];
        equipmentName[i] = equipmentName[j];
        equipmentName[j] = tName;
        
        string tCat = equipmentCat[i];
        equipmentCat[i] = equipmentCat[j];
        equipmentCat[j] = tCat;
        
        int tQty = equipmentQty[i];
        equipmentQty[i] = equipmentQty[j];
        equipmentQty[j] = tQty;
        
        int tAvail = equipmentAvail[i];
        equipmentAvail[i] = equipmentAvail[j];
        equipmentAvail[j] = tAvail;
        
        string tCond = equipmentCond[i];
        equipmentCond[i] = equipmentCond[j];
        equipmentCond[j] = tCond;
        
        float tPrice = equipmentPrice[i];
        equipmentPrice[i] = equipmentPrice[j];
        equipmentPrice[j] = tPrice;
      }
    }
  }

  cout << "\n  Sorted! Result:\n";
  cout << "  " << string(55, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(14) << left << "Category"
       << setw(12) << left << "Price(PKR)"
       << "\n";
  cout << "  " << string(55, '-') << "\n";

  for (int i = 0; i < equipmentCount; i++)
  {
    cout << "  "
         << setw(4) << left << equipmentId[i]
         << setw(16) << left << equipmentName[i]
         << setw(14) << left << equipmentCat[i]
         << setw(12) << left << equipmentPrice[i]
         << "\n";
  }
}

void viewByCategory()
{
  clearScreen();
  cout << "\n  VIEW EQUIPMENT BY CATEGORY\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter category (Electronics/Chemistry/Physics/Biology): ";
  string searchCat;
  cin >> searchCat;

  bool found = false;
  cout << "\n  " << string(65, '-') << "\n";
  cout << "  "
       << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(6) << left << "Qty"
       << setw(7) << left << "Avail"
       << setw(10) << left << "Condition"
       << setw(12) << left << "Price(PKR)"
       << "\n";
  cout << "  " << string(65, '-') << "\n";

  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentCat[i] == searchCat)
    {
      cout << "  "
           << setw(4) << left << equipmentId[i]
           << setw(16) << left << equipmentName[i]
           << setw(6) << left << equipmentQty[i]
           << setw(7) << left << equipmentAvail[i]
           << setw(10) << left << equipmentCond[i]
           << setw(12) << left << equipmentPrice[i]
           << "\n";
      found = true;
    }
  }
  if (!found)
    cout << "\n  No equipment found in this category!\n";
}

void manageTechnicians()
{
  clearScreen();
  cout << "\n";
  cout << "  |=======================================================|\n";
  cout << "  |                MANAGE TECHNICIANS                     |\n";
  cout << "  |=======================================================|\n";
  cout << "  |   [1]   View All Technicians                          |\n";
  cout << "  |   [2]   Add Technician                                |\n";
  cout << "  |   [3]   Delete Technician                             |\n";
  cout << "  |=======================================================|\n";
  cout << "  Choose option: ";

  int opt;
  cin >> opt;

  if (opt == 1)
  {
    clearScreen();
    cout << "\n  ALL TECHNICIANS\n";
    cout << "  " << string(40, '-') << "\n";
    cout << "  "
         << setw(5) << left << "No."
         << setw(16) << left << "Name"
         << setw(12) << left << "Username"
         << "\n";
    cout << "  " << string(40, '-') << "\n";

    for (int i = 0; i < techCount; i++)
    {
      cout << "  "
           << setw(5) << left << i + 1
           << setw(16) << left << techName[i]
           << setw(12) << left << techUsername[i]
           << "\n";
    }
  }
  else if (opt == 2)
  {
    clearScreen();
    cout << "\n  ADD TECHNICIAN\n";
    cout << "  -----------------------------------------\n\n";

    if (techCount >= MAX_TECH)
    {
      cout << "  Technician limit reached!\n";
    }
    else
    {
      cout << "  Name     : ";
      cin >> techName[techCount];
      cout << "  Username : ";
      cin >> techUsername[techCount];
      techCount++;
      cout << "\n  Technician added! Default password is 123.\n";
    }
  }
  else if (opt == 3)
  {
    clearScreen();
    cout << "\n  DELETE TECHNICIAN\n";
    cout << "  -----------------------------------------\n\n";
    cout << "  Enter username to delete: ";
    string delUser;
    cin >> delUser;

    bool found = false;
    for (int i = 0; i < techCount; i++)
    {
      if (techUsername[i] == delUser)
      {
        for (int j = i; j < techCount - 1; j++)
        {
          techName[j] = techName[j + 1];
          techUsername[j] = techUsername[j + 1];
        }
        techCount--;
        cout << "\n  Technician deleted!\n";
        found = true;
        break;
      }
    }
    if (!found)
      cout << "\n  Technician not found!\n";
  }
  else
  {
    cout << "\n  Invalid option!\n";
  }
}

void viewHistory()
{
  clearScreen();
  cout << "\n  ACTIVITY HISTORY\n";
  cout << "  " << string(55, '-') << "\n";
  cout << "  "
       << setw(4) << left << "No."
       << setw(10) << left << "Action"
       << setw(20) << left << "Item"
       << setw(14) << left << "By"
       << "\n";
  cout << "  " << string(55, '-') << "\n";

  if (historyCount == 0)
  {
    cout << "\n  No history yet.\n";
    return;
  }
  for (int i = 0; i < historyCount; i++)
  {
    cout << "  "
         << setw(4) << left << i + 1
         << setw(10) << left << historyAction[i]
         << setw(20) << left << historyItem[i]
         << setw(14) << left << historyBy[i]
         << "\n";
  }
}

////////////////////////////////////////////////////////////////
// TECHNICIAN FUNCTIONS
////////////////////////////////////////////////////////////////

void borrowEquipment(int techIdx)
{
  clearScreen();
  cout << "\n  BORROW EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter equipment ID: ";
  int borrowEquipId;
  cin >> borrowEquipId;

  bool found = false;
  for (int i = 0; i < equipmentCount; i++)
  {
    if (equipmentId[i] == borrowEquipId)
    {
      found = true;
      if (equipmentAvail[i] <= 0)
      {
        cout << "\n  Sorry! This equipment is not available.\n";
      }
      else
      {
        cout << "\n  Equipment    : " << equipmentName[i] << "\n";
        cout << "  Borrower Name: ";
        string bName;
        cin >> bName;
        cout << "  Roll Number  : ";
        string bRoll;
        cin >> bRoll;
        cout << "  Borrow Date  (DD/MM/YYYY): ";
        string bDate;
        cin >> bDate;
        cout << "  Return Date  (DD/MM/YYYY): ";
        string rDate;
        cin >> rDate;

        borrowId[borrowCount] = nextBorrowId++;
        borrowEquipName[borrowCount] = equipmentName[i];
        borrowerName[borrowCount] = bName;
        borrowerRoll[borrowCount] = bRoll;
        borrowDate[borrowCount] = bDate;
        returnDate[borrowCount] = rDate;
        borrowStatus[borrowCount] = "Borrowed";
        borrowIssuedBy[borrowCount] = techName[techIdx];
        borrowCount++;
        equipmentAvail[i]--;

        addHistory("Borrowed", equipmentName[i], techName[techIdx]);
        cout << "\n  Equipment issued! Borrow ID: " << nextBorrowId - 1 << "\n";
      }
      break;
    }
  }
  if (!found)
    cout << "\n  Equipment ID not found!\n";
}

void returnEquipment(int techIdx)
{
  clearScreen();
  cout << "\n  RETURN EQUIPMENT\n";
  cout << "  -----------------------------------------\n\n";
  cout << "  Enter Borrow ID: ";
  int retId;
  cin >> retId;

  bool found = false;
  for (int i = 0; i < borrowCount; i++)
  {
    if (borrowId[i] == retId && borrowStatus[i] == "Borrowed")
    {
      found = true;
      cout << "\n  Equipment : " << borrowEquipName[i] << "\n";
      cout << "  Borrower  : " << borrowerName[i] << "\n";
      cout << "  Confirm return? (y/n): ";
      char confirm;
      cin >> confirm;

      if (confirm == 'y' || confirm == 'Y')
      {
        borrowStatus[i] = "Returned";

        for (int j = 0; j < equipmentCount; j++)
        {
          if (equipmentName[j] == borrowEquipName[i])
          {
            equipmentAvail[j]++;
            break;
          }
        }
        addHistory("Returned", borrowEquipName[i], techName[techIdx]);
        cout << "\n  Equipment returned successfully!\n";
      }
      else
      {
        cout << "\n  Return cancelled.\n";
      }
      break;
    }
  }
  if (!found)
    cout << "\n  Borrow ID not found or already returned!\n";
}