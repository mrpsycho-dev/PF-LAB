#include <iostream>
#include <string>
using namespace std;

int main(){
  
string filmTitle;
float adultTicketPrice, childTicketPrice, charityPercent;
int adultTicketsSold, childTicketsSold;
float grossAmount, charityAmount, netAmount;
cout<<"Enter movie title: ";
cin>>filmTitle;
 
cout<<"Adult ticket price: ";
cin>>adultTicketPrice;

cout<<"Child ticket price: ";
cin>>childTicketPrice;
 
cout<<"Number of adult tickets sold: ";
cin>>adultTicketsSold;
 
cout<<"Number of child tickets sold: ";
cin>>childTicketsSold;
 
cout<<"Donation percentage: ";
cin>>charityPercent;

grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);

charityAmount = grossAmount * (charityPercent / 100);
 
netAmount = grossAmount - charityAmount;
cout<<"Total collected: "<<grossAmount<<endl;
cout<<"Donated to charity: "<<charityAmount<<endl;
cout<<"Remaining amount: "<<netAmount;
 
return 0;
 
};
