#include <iostream>
using namespace std;

int main() {
  
 string country;
 double ticketPrice, finalPrice;

 cout << "Country: ";
 cin >> country;

 cout << "Ticket Price: ";
 cin >> ticketPrice;
 
 if (country == "Ireland") {
 finalPrice = ticketPrice - (ticketPrice * 0.10);
 } else {
 finalPrice = ticketPrice - (ticketPrice * 0.05);
 }

 cout << "Discounted Price: " << finalPrice;

 return 0;
}; 
