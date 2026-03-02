#include<iostream>
using namespace std;

int main(){
  
string movieName;
float adultPrice, childPrice, donationPercent;
int adultSold, childSold;
float totalAmount, donationAmount, remainingAmount;

 cout<<"Enter the movie name: ";
 getline(cin, movieName);

 cout<<"Enter adult ticket price: ";
 cin>>adultPrice;

 cout<<"Enter child ticket price: ";
 cin>>childPrice;

 cout<<"Number of adult tickets sold: ";
 cin>>adultSold;

 cout<<"Number of child tickets sold: ";
 cin>>childSold;

 cout<<"Enter donation percentage: ";
 cin>>donationPercent;

 totalAmount = (adultPrice * adultSold) + (childPrice * childSold);
 donationAmount = totalAmount * (donationPercent / 100);
 remainingAmount = totalAmount - donationAmount;

 cout<<"Movie Name: "<<movieName<<endl;
 cout<<"Total Revenue: "<<totalAmount<<endl;
 cout<<"Donation Amount: "<<donationAmount<<endl;
 cout<<"Remaining After Donation: "<<remainingAmount;

 return 0;
 
};
