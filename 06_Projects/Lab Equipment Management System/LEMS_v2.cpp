#include <iostream>
#include <fstream>
#include <iomanip> // i used this for the setw function
#include <conio.h>
using namespace std;

const int MAX = 200;
const int MAXTECH = 10;

// equipment
int eqCount = 0, nextEqId = 1;
int eqId[MAX], eqQty[MAX], eqAvail[MAX];
string eqName[MAX], eqCat[MAX], eqCond[MAX];
float eqPrice[MAX];

// borrow records
int brCount = 0, nextBrId = 1;
int brId[MAX];
string brEquip[MAX], brBorrower[MAX], brRoll[MAX];
string brDate[MAX], brDue[MAX], brStatus[MAX], brBy[MAX];

// technicians
int techCount = 0;
string techUser[MAXTECH], techPass[MAXTECH], techName[MAXTECH], techSec[MAXTECH];

// history log
int histCount = 0;
string histAct[MAX], histItem[MAX], histWho[MAX];

// admin account
string aUser = "admin", aPass = "123", aSec = "lems";

// basic helpers

void cls() { system("cls"); }

void pause()
{
  cout << "\n  Press any key...";
  getch();
}

// draw a line of dashes
void line(int n)
{
  cout << "  ";
  for (int i = 0; i < n; i++)
    cout << "-";
  cout << endl;
}

void heading(string t)
{
  cls();
  cout << "\n================================================\n";
  cout << "  " << t << endl;
  cout << "================================================\n\n";
}

string getStr(string msg)
{
  string s;
  cout << msg;
  // cin.ignore();
  // getline(cin, s);
  cin >> s;
  return s;
}

int getInt(string msg)
{
  int n;
  cout << msg;
  cin >> n;
  return n;
}

float getFloat(string msg)
{
  float n;
  cout << msg;
  cin >> n;
  return n;
}

bool confirm(string msg)
{
  char c;
  cout << "  " << msg << " (y/n): ";
  cin >> c;
  return c == 'y' || c == 'Y'; // if 'y' or 'Y' then true otherwise anything else is false.
}

// file save / load
void saveAdmin()
{
  fstream f;
  f.open("admin.txt", ios::out);
  f << aUser << endl
    << aPass << endl
    << aSec << endl;
  f.close();
}

void loadAdmin()
{
  fstream f;
  f.open("admin.txt", ios::in);
  if (!f)
  {
    saveAdmin();
    return;
  }
  f >> aUser >> aPass >> aSec;
  f.close();
}

void saveTech()
{
  fstream f;
  f.open("tech.txt", ios::out);
  f << techCount << endl;
  for (int i = 0; i < techCount; i++)
    f << techUser[i] << " " << techPass[i] << " " << techName[i] << " " << techSec[i] << endl;
  f.close();
}

void loadTech()
{
  fstream f;
  f.open("tech.txt", ios::in);
  if (!f)
  {
    // two technicians
    techCount = 2;
    techUser[0] = "tech1";
    techPass[0] = "123";
    techName[0] = "Dr.Sara";
    techSec[0] = "sara";
    techUser[1] = "tech2";
    techPass[1] = "123";
    techName[1] = "Mr.Hamza";
    techSec[1] = "hamza";
    saveTech();
    return;
  }
  f >> techCount;
  for (int i = 0; i < techCount; i++)
    f >> techUser[i] >> techPass[i] >> techName[i] >> techSec[i];
  f.close();
}

void saveEquip()
{
  fstream f;
  f.open("equip.txt", ios::out);
  f << eqCount << " " << nextEqId << endl;
  for (int i = 0; i < eqCount; i++)
    f << eqId[i] << " " << eqName[i] << " " << eqCat[i] << " "
      << eqQty[i] << " " << eqAvail[i] << " " << eqCond[i] << " " << eqPrice[i] << endl;
  f.close();
}

void loadEquip()
{
  fstream f;
  f.open("equip.txt", ios::in);
  if (!f)
  {
    // five default items on first run
    eqCount = 5;
    nextEqId = 6;
    string names[] = {"Microscope", "Oscilloscope", "BunsenBurner", "Voltmeter", "Centrifuge"};
    string cats[] = {"Biology", "Electronics", "Chemistry", "Electronics", "Biology"};
    int qtys[] = {5, 3, 8, 6, 2};
    string conds[] = {"Good", "Good", "Fair", "Good", "Fair"};
    float prices[] = {15000, 25000, 2000, 5000, 50000};
    for (int i = 0; i < eqCount; i++)
    {
      eqId[i] = i + 1;
      eqName[i] = names[i];
      eqCat[i] = cats[i];
      eqQty[i] = qtys[i];
      eqAvail[i] = qtys[i];
      eqCond[i] = conds[i];
      eqPrice[i] = prices[i];
    }
    saveEquip();
    return;
  }
  f >> eqCount >> nextEqId;
  for (int i = 0; i < eqCount; i++)
    f >> eqId[i] >> eqName[i] >> eqCat[i] >> eqQty[i] >> eqAvail[i] >> eqCond[i] >> eqPrice[i];
  f.close();
}

void saveBorrow()
{
  fstream f;
  f.open("borrow.txt", ios::out);
  f << brCount << " " << nextBrId << endl;
  for (int i = 0; i < brCount; i++)
    f << brId[i] << " " << brEquip[i] << " " << brBorrower[i] << " "
      << brRoll[i] << " " << brDate[i] << " " << brDue[i] << " "
      << brStatus[i] << " " << brBy[i] << endl;
  f.close();
}

void loadBorrow()
{
  fstream f;
  f.open("borrow.txt", ios::in);
  if (!f)
  {
    saveBorrow();
    return;
  }
  f >> brCount >> nextBrId;
  for (int i = 0; i < brCount; i++)
    f >> brId[i] >> brEquip[i] >> brBorrower[i] >> brRoll[i] >> brDate[i] >> brDue[i] >> brStatus[i] >> brBy[i];
  f.close();
}

void saveHist()
{
  fstream f;
  f.open("history.txt", ios::out);
  f << histCount << endl;
  for (int i = 0; i < histCount; i++)
    f << histAct[i] << " " << histItem[i] << " " << histWho[i] << endl;
  f.close();
}

void loadHist()
{
  fstream f;
  f.open("history.txt", ios::in);
  if (!f)
  {
    saveHist();
    return;
  }
  f >> histCount;
  for (int i = 0; i < histCount; i++)
    f >> histAct[i] >> histItem[i] >> histWho[i];
  f.close();
}

void loadAll()
{
  loadAdmin();
  loadTech();
  loadEquip();
  loadBorrow();
  loadHist();
}

// history

void addHist(string act, string item, string who)
{
  histAct[histCount] = act;
  histItem[histCount] = item;
  histWho[histCount] = who;
  histCount++;
  saveHist();
}

void viewHistory()
{
  heading("ACTIVITY HISTORY");
  if (histCount == 0)
  {
    cout << "  Nothing recorded yet.\n";
    return;
  }
  cout << "  " << setw(5) << left << "No"
       << setw(12) << left << "Action"
       << setw(22) << left << "Item"
       << setw(15) << left << "By" << endl;
  line(54);
  for (int i = 0; i < histCount; i++)
    cout << "  " << setw(5) << left << i + 1
         << setw(12) << left << histAct[i]
         << setw(22) << left << histItem[i]
         << setw(15) << left << histWho[i] << endl;
}

// equipment display helpers

// find equipment index by id, returns -1 if not found
int findEq(int id)
{
  for (int i = 0; i < eqCount; i++)
    if (eqId[i] == id)
      return i;
  return -1;
}

void eqTableHeader()
{
  cout << "  " << setw(4) << left << "ID"
       << setw(16) << left << "Name"
       << setw(14) << left << "Category"
       << setw(6) << left << "Qty"
       << setw(7) << left << "Avail"
       << setw(10) << left << "Condition"
       << setw(12) << left << "Price(PKR)" << endl;
  line(70);
}

void eqRow(int i)
{
  cout << "  " << setw(4) << left << eqId[i]
       << setw(16) << left << eqName[i]
       << setw(14) << left << eqCat[i]
       << setw(6) << left << eqQty[i]
       << setw(7) << left << eqAvail[i]
       << setw(10) << left << eqCond[i]
       << setw(12) << left << eqPrice[i] << endl;
}

// one function handles all three list views with a filter
void viewEqList(string title, string filter, string val)
{
  heading(title);
  eqTableHeader();
  bool any = false;
  for (int i = 0; i < eqCount; i++)
  {
    bool show = false;
    if (filter == "all")
      show = true;
    else if (filter == "avail" && eqAvail[i] > 0)
      show = true;
    else if (filter == "cat" && eqCat[i] == val)
      show = true;
    else if (filter == "name" && eqName[i] == val)
      show = true;
    if (show)
    {
      eqRow(i);
      any = true;
    }
  }
  if (!any)
    cout << "  Nothing to show.\n";
}

void searchByName()
{
  string name = getStr("  Enter equipment name: ");
  viewEqList("SEARCH RESULTS", "name", name);
}

void viewByCat()
{
  string cat = getStr("  Category (Electronics/Chemistry/Physics/Biology): ");
  viewEqList("EQUIPMENT BY CATEGORY", "cat", cat);
}

void eqDetails()
{
  heading("EQUIPMENT DETAILS");
  int id = getInt("  Enter equipment ID: ");
  int i = findEq(id);
  if (i == -1)
  {
    cout << "  Not found!\n";
    return;
  }
  line(36);
  cout << "  ID        : " << eqId[i] << endl;
  cout << "  Name      : " << eqName[i] << endl;
  cout << "  Category  : " << eqCat[i] << endl;
  cout << "  Quantity  : " << eqQty[i] << endl;
  cout << "  Available : " << eqAvail[i] << endl;
  cout << "  Condition : " << eqCond[i] << endl;
  cout << "  Price     : PKR " << eqPrice[i] << endl;
  line(36);
}

// equipment add, update and delete...CRUD

void addEq()
{
  heading("ADD NEW EQUIPMENT");
  int i = eqCount;
  eqId[i] = nextEqId++;
  eqName[i] = getStr("  Name       : ");
  eqCat[i] = getStr("  Category   : ");
  eqQty[i] = getInt("  Quantity   : ");
  eqAvail[i] = eqQty[i];
  eqCond[i] = getStr("  Condition  : ");
  eqPrice[i] = getFloat("  Price(PKR) : ");
  eqCount++;
  addHist("Added", eqName[i], "Admin");
  saveEquip();
  cout << "Equipment added!\n";
}

void updateEq()
{
  heading("UPDATE EQUIPMENT");
  int id = getInt("  Enter equipment ID: ");
  int i = findEq(id);
  if (i == -1)
  {
    cout << "  Not found!\n";
    return;
  }

  // show the output
  cout << "  Current -> Name: " << eqName[i] << "  Cat: " << eqCat[i]
       << "  Qty: " << eqQty[i] << "  Price: " << eqPrice[i] << "\n\n";

  eqName[i] = getStr("  New Name      : ");
  eqCat[i] = getStr("  New Category  : ");
  int old = eqQty[i];
  eqQty[i] = getInt("  New Quantity  : ");
  eqAvail[i] = eqAvail[i] + (eqQty[i] - old); // this keeps track of borrowed items.. suppose 3 iterms were borrowed and total were 10 so updated value is now 15, then new available quantity is 15-3 = 12
  if (eqAvail[i] < 0)
    eqAvail[i] = 0;
  eqCond[i] = getStr("  New Condition : ");
  eqPrice[i] = getFloat("  New Price     : ");
  addHist("Updated", eqName[i], "Admin");
  saveEquip();
  cout << "\n  Equipment updated!\n";
}

void deleteEq()
{
  heading("DELETE EQUIPMENT");
  int id = getInt("Enter equipment ID: ");
  int i = findEq(id);
  if (i == -1)
  {
    cout << "Not found!\n";
    return;
  }
  if (!confirm("Delete " + eqName[i] + "?"))
  {
    cout << "Cancelled.\n";
    return;
  }

  string deleted = eqName[i];

  // shift everything left to fill the gap
  for (int j = i; j < eqCount - 1; j++)
  {
    eqId[j] = eqId[j + 1];
    eqName[j] = eqName[j + 1];
    eqCat[j] = eqCat[j + 1];
    eqQty[j] = eqQty[j + 1];
    eqAvail[j] = eqAvail[j + 1];
    eqCond[j] = eqCond[j + 1];
    eqPrice[j] = eqPrice[j + 1];
  }
  eqCount--;
  addHist("Deleted", deleted, "Admin");
  saveEquip();
  cout << "\n  Deleted!\n";
}

// sorting of equipments

void sortEq()
{
  cls();
  cout << "  [1] Price Low to High\n";
  cout << "  [2] Price High to Low\n";
  cout << "  [3] Name  A to Z\n";
  cout << "  [4] Name  Z to A\n";
  int ch = getInt("  Choose: ");
  if (ch < 1 || ch > 4)
  {
    cout << "  Invalid!\n";
    return;
  }

  for (int i = 0; i < eqCount; i++)
  {
    for (int j = i + 1; j < eqCount; j++)
    {
      bool swap = false;
      if (ch == 1 && eqPrice[i] > eqPrice[j])
        swap = true;
      if (ch == 2 && eqPrice[i] < eqPrice[j])
        swap = true;
      if (ch == 3 && eqName[i] > eqName[j])
        swap = true;
      if (ch == 4 && eqName[i] < eqName[j])
        swap = true;

      if (swap)
      {

        int ti;
        string ts;
        float tf;

        ti = eqId[i];
        eqId[i] = eqId[j];
        eqId[j] = ti;

        ts = eqName[i];
        eqName[i] = eqName[j];
        eqName[j] = ts;

        ts = eqCat[i];
        eqCat[i] = eqCat[j];
        eqCat[j] = ts;

        ti = eqQty[i];
        eqQty[i] = eqQty[j];
        eqQty[j] = ti;

        ti = eqAvail[i];
        eqAvail[i] = eqAvail[j];
        eqAvail[j] = ti;

        ts = eqCond[i];
        eqCond[i] = eqCond[j];
        eqCond[j] = ts;

        tf = eqPrice[i];
        eqPrice[i] = eqPrice[j];
        eqPrice[j] = tf;
      }
    }
  }
  saveEquip();
  cout << "\nSorted! Result:\n";
  viewEqList("SORTED EQUIPMENT", "all", "");
}

// borrow / return

int findBr(int id)
{
  for (int i = 0; i < brCount; i++)
    if (brId[i] == id)
      return i;
  return -1;
}

void brTableHeader()
{
  cout << "  " << setw(4) << left << "ID"
       << setw(16) << left << "Equipment"
       << setw(14) << left << "Borrower"
       << setw(12) << left << "Roll"
       << setw(12) << left << "Date"
       << setw(12) << left << "Due"
       << setw(10) << left << "Status" << endl;
  line(80);
}

// one function for all borrow views, filter decides what shows
void viewBorrow(string title, string filter, string val)
{
  heading(title);
  brTableHeader();
  if (brCount == 0)
  {
    cout << "  No records yet.\n";
    return;
  }
  bool any = false;
  for (int i = 0; i < brCount; i++)
  {
    bool show = false;
    if (filter == "all")
      show = true;
    else if (filter == "status" && brStatus[i] == val)
      show = true;
    else if (filter == "by" && brBy[i] == val)
      show = true;
    if (show)
    {
      cout << "  " << setw(4) << left << brId[i]
           << setw(16) << left << brEquip[i]
           << setw(14) << left << brBorrower[i]
           << setw(12) << left << brRoll[i]
           << setw(12) << left << brDate[i]
           << setw(12) << left << brDue[i]
           << setw(10) << left << brStatus[i] << endl;
      any = true;
    }
  }
  if (!any)
    cout << "  No matching records.\n";
}

void borrowEq(int techIdx)
{
  heading("BORROW EQUIPMENT");
  int id = getInt("  Equipment ID: ");
  int i = findEq(id);
  if (i == -1)
  {
    cout << "  Equipment not found!\n";
    return;
  }
  if (eqAvail[i] <= 0)
  {
    cout << "  Not available right now!\n";
    return;
  }

  cout << "\n  Equipment: " << eqName[i] << "\n\n";
  brId[brCount] = nextBrId++;
  brEquip[brCount] = eqName[i];
  brBorrower[brCount] = getStr("  Borrower Name : ");
  brRoll[brCount] = getStr("  Roll No       : ");
  brDate[brCount] = getStr("  Borrow Date   : ");
  brDue[brCount] = getStr("  Due Date      : ");
  brStatus[brCount] = "Borrowed";
  brBy[brCount] = techName[techIdx];
  brCount++;
  eqAvail[i]--;

  addHist("Borrowed", eqName[i], techName[techIdx]);
  saveBorrow();
  saveEquip();
  cout << "\n  Done! Record ID: " << nextBrId - 1 << endl;
}

void returnEq(int techIdx)
{
  heading("RETURN EQUIPMENT");
  int id = getInt("  Enter Borrow Record ID: ");
  int i = findBr(id);
  if (i == -1 || brStatus[i] != "Borrowed")
  {
    cout << "  Record not found or already returned!\n";
    return;
  }

  cout << "\n  Equipment : " << brEquip[i] << endl;
  cout << "  Borrower  : " << brBorrower[i] << endl;
  if (!confirm("Confirm return?"))
  {
    cout << "  Cancelled.\n";
    return;
  }

  brStatus[i] = "Returned";

  // add back to available count
  for (int j = 0; j < eqCount; j++)
    if (eqName[j] == brEquip[i])
    {
      eqAvail[j]++;
      break;
    }

  addHist("Returned", brEquip[i], techName[techIdx]);
  saveBorrow();
  saveEquip();
  cout << "\n  Returned successfully!\n";
}

// technician management

int findTech(string user)
{
  for (int i = 0; i < techCount; i++)
    if (techUser[i] == user)
      return i;
  return -1;
}

void showTechs()
{
  heading("ALL TECHNICIANS");
  cout << "  " << setw(5) << left << "No" << setw(18) << left << "Name" << setw(14) << left << "Username" << endl;
  line(38);
  for (int i = 0; i < techCount; i++)
    cout << "  " << setw(5) << left << i + 1
         << setw(18) << left << techName[i]
         << setw(14) << left << techUser[i] << endl;
}

void addTech()
{
  heading("ADD TECHNICIAN");
  if (techCount >= MAXTECH)
  {
    cout << "  Technician limit reached!\n";
    return;
  }
  techName[techCount] = getStr("  Full name      : ");
  techUser[techCount] = getStr("  Username       : ");
  techSec[techCount] = getStr("  Security answer: ");
  techPass[techCount] = "123"; // default password
  techCount++;
  saveTech();
  cout << "\n  Added! Default password is: 123\n";
}

void deleteTech()
{
  heading("DELETE TECHNICIAN");
  string u = getStr("  Enter username: ");
  int i = findTech(u);
  if (i == -1)
  {
    cout << "  Not found!\n";
    return;
  }
  if (!confirm("Delete " + techName[i] + "?"))
  {
    cout << "  Cancelled.\n";
    return;
  }
  for (int j = i; j < techCount - 1; j++)
  {
    techUser[j] = techUser[j + 1];
    techPass[j] = techPass[j + 1];
    techName[j] = techName[j + 1];
    techSec[j] = techSec[j + 1];
  }
  techCount--;
  saveTech();
  cout << "\n  Deleted!\n";
}

void manageTechs()
{
  cls();
  cout << "\n  [1] View All Technicians\n  [2] Add Technician\n  [3] Delete Technician\n";
  int ch = getInt("  Choose: ");
  if (ch == 1)
    showTechs();
  else if (ch == 2)
    addTech();
  else if (ch == 3)
    deleteTech();
  else
    cout << "  Invalid!\n";
}

// forgot password flows

void forgotAdminPass()
{
  heading("FORGOT ADMIN PASSWORD");
  cout << "  Security question: What is this system's acronym?\n";
  string ans = getStr("  Answer: ");
  if (ans != aSec)
  {
    cout << "  Wrong answer!\n";
    pause();
    return;
  }
  aPass = getStr("  New password: ");
  saveAdmin();
  cout << "\n  Password reset!\n";
  pause();
}

void forgotTechPass()
{
  heading("FORGOT TECHNICIAN PASSWORD");
  string u = getStr("  Your username: ");
  int i = findTech(u);
  if (i == -1)
  {
    cout << "  Username not found!\n";
    pause();
    return;
  }
  cout << "  Security question: What is your registered security answer?\n";
  string ans = getStr("  Answer: ");
  if (ans != techSec[i])
  {
    cout << "  Wrong answer!\n";
    pause();
    return;
  }
  techPass[i] = getStr("  New password: ");
  saveTech();
  cout << "\n  Password reset!\n";
  pause();
}

// account settings

void adminAccSettings()
{
  cls();
  cout << "\n  [1] Change Username\n  [2] Change Password\n  [3] Change Security Answer\n";
  int ch = getInt("  Choose: ");
  if (ch == 1)
  {
    aUser = getStr("  New username: ");
    saveAdmin();
    cout << "  Done!\n";
  }
  else if (ch == 2)
  {
    if (getStr("  Current password: ") != aPass)
    {
      cout << "  Wrong password!\n";
      return;
    }
    aPass = getStr("  New password: ");
    saveAdmin();
    cout << "  Done!\n";
  }
  else if (ch == 3)
  {
    aSec = getStr("  New security answer: ");
    saveAdmin();
    cout << "  Done!\n";
  }
  else
    cout << "  Invalid!\n";
}

void techAccSettings(int idx)
{
  cls();
  cout << "\n  [1] Change Password\n  [2] Change Username\n  [3] Change Security Answer\n";
  int ch = getInt("  Choose: ");
  if (ch == 1)
  {
    if (getStr("  Current password: ") != techPass[idx])
    {
      cout << "  Wrong password!\n";
      return;
    }
    techPass[idx] = getStr("  New password: ");
    saveTech();
    cout << "  Done!\n";
  }
  else if (ch == 2)
  {
    techUser[idx] = getStr("  New username: ");
    saveTech();
    cout << "  Done!\n";
  }
  else if (ch == 3)
  {
    techSec[idx] = getStr("  New security answer: ");
    saveTech();
    cout << "  Done!\n";
  }
  else
    cout << "  Invalid!\n";
}

// login screens

bool adminLogin()
{
  for (int attempt = 1; attempt <= 3; attempt++)
  {
    cls();
    cout << "\n  ADMIN LOGIN  (Attempt " << attempt << " of 3)\n\n";
    string u = getStr("  Username: ");
    string p = getStr("  Password: ");
    if (u == aUser && p == aPass)
    {
      cout << "\n  Welcome, Admin!\n";
      pause();
      return true;
    }
    cout << "\n  Wrong credentials.\n";
    if (attempt == 2 && confirm("Forgot your password?"))
      forgotAdminPass();
    else
      pause();
  }
  cout << "\n  Too many failed attempts.\n";
  pause();
  return false;
}

// pass value by reference. meaning it directly changes the index...
bool techLogin(int &idx)
{
  for (int attempt = 1; attempt <= 3; attempt++)
  {
    cls();
    cout << "\n  TECHNICIAN LOGIN  (Attempt " << attempt << " of 3)\n";
    string u = getStr("  Username: ");
    string p = getStr("  Password: ");
    int i = findTech(u);
    if (i != -1 && techPass[i] == p)
    {
      idx = i;
      cout << "\n  Welcome, " << techName[i] << "!\n";
      pause();
      return true;
    }
    cout << "\n  Wrong credentials.\n";
    if (attempt == 2 && confirm("Forgot your password?"))
      forgotTechPass();
    else
      pause();
  }
  cout << "\n  Too many failed attempts.\n";
  pause();
  return false;
}

// menus

void showMainMenu()
{
  cout << R"(
  |=============================================|
  |       LAB EQUIPMENT MANAGEMENT SYSTEM       |
  |                 L  E  M  S                  |
  |=============================================|
  |  [1]  Admin Login                           |
  |  [2]  Technician Login                      |
  |  [3]  Exit                                  |
  |=============================================|
      Choose: )";
}

void showAdminMenu()
{

  cout << R"(
  |=============================================|
  |             ADMIN DASHBOARD                 |
  |=============================================|
  |  [1]  Add Equipment                         |
  |  [2]  View All Equipment                    |
  |  [3]  Search Equipment                      |
  |  [4]  Update Equipment                      |
  |  [5]  Delete Equipment                      |
  |  [6]  View Borrow Records                   |
  |  [7]  Sort Equipment                        |
  |  [8]  View by Category                      |
  |  [9]  Manage Technicians                    |
  | [10]  Equipment Details                     |
  | [11]  Activity History                      |
  | [12]  Account Settings                      |
  | [13]  Logout                                |
  |=============================================|
      Choose: )";
}

void showTechMenu()
{
  cout << R"(
|=============================================|
|           TECHNICIAN DASHBOARD              |
|=============================================|
|  [1]  View Available Equipment              |
|  [2]  Search Equipment                      |
|  [3]  Borrow Equipment                      |
|  [4]  Return Equipment                      |
|  [5]  My Issued Records                     |
|  [6]  Active Borrowings                     |
|  [7]  Equipment Details                     |
|  [8]  Borrow History                        |
|  [9]  Account Settings                      |
| [10]  Logout                                |
|=============================================|
    Choose: )";
}

// admin and tech sessions

void adminSection()
{
  if (!adminLogin())
    return;

  while (true)
  {
    cls();
    showAdminMenu();
    int ch;
    cin >> ch;

    if (ch == 13)
    {
      cout << "\n  Logged out.\n";
      pause();
      break;
    }

    if (ch == 1)
      addEq();
    else if (ch == 2)
      viewEqList("ALL EQUIPMENT", "all", "");
    else if (ch == 3)
      searchByName();
    else if (ch == 4)
      updateEq();
    else if (ch == 5)
      deleteEq();
    else if (ch == 6)
      viewBorrow("ALL BORROW RECORDS", "all", "");
    else if (ch == 7)
      sortEq();
    else if (ch == 8)
      viewByCat();
    else if (ch == 9)
      manageTechs();
    else if (ch == 10)
      eqDetails();
    else if (ch == 11)
      viewHistory();
    else if (ch == 12)
      adminAccSettings();
    else
      cout << "\n  Invalid option!\n";

    pause();
  }
}

void techSection()
{
  int idx = -1;
  if (!techLogin(idx))
    return;

  while (true)
  {
    cls();
    cout << "\n  Logged in as: " << techName[idx] << endl;
    showTechMenu();
    int ch;
    cin >> ch;

    if (ch == 10)
    {
      cout << "\n  Logged out.\n";
      pause();
      break;
    }

    if (ch == 1)
      viewEqList("AVAILABLE EQUIPMENT", "avail", "");
    else if (ch == 2)
      searchByName();
    else if (ch == 3)
      borrowEq(idx);
    else if (ch == 4)
      returnEq(idx);
    else if (ch == 5)
      viewBorrow("MY ISSUED RECORDS", "by", techName[idx]);
    else if (ch == 6)
      viewBorrow("ACTIVE BORROWINGS", "status", "Borrowed");
    else if (ch == 7)
      eqDetails();
    else if (ch == 8)
      viewBorrow("BORROW HISTORY", "all", "");
    else if (ch == 9)
      techAccSettings(idx);
    else
      cout << "\n  Invalid option!\n";

    pause();
  }
}

// MAIN FUNCTION

int main()
{
  loadAll();

  while (true)
  {
    cls();
    showMainMenu();
    int ch;
    cin >> ch;

    if (ch == 1)
      adminSection();
    else if (ch == 2)
      techSection();
    else if (ch == 3)
    {
      cls();

      cout << R"(
      |=============================================|
      |           Thanks for using LEMS!            |
      |       Lab Equipment Management System       |
      |=============================================|
      )";
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