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
  
  cout<<"Name: "<< name <<endl;
  cout<<"Customer ID: "<< customerID <<endl;
  cout<< "Units consumed: " << unitsConsumed <<endl;
  cout<< "Cost per unit: Rs.35" <<endl;
  cout<< "Energy Cost: "<< cost <<endl;
  cout<< "Fixed charges: "<< fixedCharges <<endl;
  cout<< "Tax Amount: "<< tax <<endl;
  cout<< "Total Bill: "<< total <<endl;
  
}
