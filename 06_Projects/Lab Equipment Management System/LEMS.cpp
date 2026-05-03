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
