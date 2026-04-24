#include <iostream>
using namespace std;

int main(){
  
 int paintArea, width, height, singleWallArea, wallsPossible;
 cout<<"Total square meters you can paint: ";
 cin>>paintArea;
 cout<<"Width of one wall: ";
 cin>>width;
 cout<<"Height of one wall: ";
 cin>>height;
 
 
 singleWallArea = width * height;
 wallsPossible = paintArea / singleWallArea;
 
 cout<<"You can fully paint "<<wallsPossible<<" walls";
 
 return 0;
};
