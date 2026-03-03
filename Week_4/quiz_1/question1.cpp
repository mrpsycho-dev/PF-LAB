#include <iostream>
using namespace std;

main(){
  string name,customerID;
  float pmr, cmr;
  float unitsConsumed, tax, cost, fixedCharges, total;
  
  cout<<"Enter name: "; cin>> name;
  cout<<"Enter customer ID: "; cin>> customerID;
  cout<<"Enter previous meter reading (in units): "; cin>> pmr;
  cout<<"Enter current meter reading (in units): "; cin>> cmr;
  
  fixedCharges = 500;
  unitsConsumed = cmr - pmr;
  cost = (unitsConsumed * 35);
  tax = (cost + fixedCharges)*7/100;
  total = cost + tax + fixedCharges;
  
  cout<<"Name: "<< name;
  cout<<"Customer ID: "<< customerID;
  cout<< "Units consumed: " << unitsConsumed;
  cout<< "Cost per unit: Rs.35";
  cout<< "Energy Cost: "<< cost;
  cout<< "Fixed charges: "<< fixedCharges;
  cout<< "Tax Amount: "<< tax;
  cout<< "Total Bill: "<< total;
  
}
