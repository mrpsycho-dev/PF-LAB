#include <iostream>
using namespace std;

int main(){
  
float bagWeight, bagPrice, coverArea;
float pricePerPound, pricePerSqFoot;
cout<<"Enter bag size in pounds: ";
cin>>bagWeight;
cout<<"Enter total price of bag: ";
cin>>bagPrice;
cout<<"Enter area covered (square feet): ";
cin>>coverArea;
pricePerPound = bagPrice / bagWeight;
pricePerSqFoot = bagPrice / coverArea;
cout<<"Cost per pound: "<<pricePerPound<<endl;
cout<<"Cost per square foot: "<<pricePerSqFoot;
 
return 0;
};
