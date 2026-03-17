#include<iostream>
using namespace std;

int main(){
    int cost;
    cout << "Enter the cost of the dress : ";
    cin >> cost;
    
    if(cost < 1500){
        cout << "Buy the Dress";
    }
    else{
        cout << "Don't buy the Dress";
    }
}