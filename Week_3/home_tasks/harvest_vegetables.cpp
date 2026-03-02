#include <iostream>
using namespace std;

int main(){

 float vegetableRate, fruitRate;
 int vegetableKg, fruitKg;
 float coinsTotal, rupeesTotal;
 
 cout<<"Vegetable price per kg (coins): ";
 cin>>vegetableRate;
 
 cout<<"Fruit price per kg (coins): ";
 cin>>fruitRate;
 
 cout<<"Total kg of vegetables: ";
 cin>>vegetableKg;
 
 cout<<"Total kg of fruits: ";
 cin>>fruitKg;
 
 coinsTotal = (vegetableRate * vegetableKg) + (fruitRate * fruitKg);
 
 rupeesTotal = coinsTotal / 1.94;
 cout<<"Total earnings in rupees: "<<rupeesTotal;
 
 return 0;
 
};