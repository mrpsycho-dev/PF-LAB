#include<iostream>
using namespace std;
int main(){
  int n; cin>>n;
  string productNames[n];
  float prices[n];
  int quantity[n];
  
  for (int i=0; i<n; i++){
    cout<<"Enter name of product "<<i+1<<": "; cin>> productNames[i];
    cout<<"Price of "<<productNames[i]<<": "; cin>>prices[i];
    cout<<"Quantity of "<<productNames[i]<<": "; cin>>quantity[i];
  }
  
  cout<<R"(
 ---------------- Product Inventory Report --------------
 --------------------------------------------------------)"<<endl;
 
 for(int i=0; i<n;i++){
  cout<< productNames[i]<<": $" <<prices[i]<<"," << quantity[i]<<" in stock, Total value: "<<prices[i]*quantity[i]<<endl;
 }

}