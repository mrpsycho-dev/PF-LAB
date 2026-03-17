#include<iostream>
using namespace std;

int main()
{
    char going;
    cout << "Are your friends going? (Press Y for yes)";
    cin >> going;
    
    if (going == 'y'){
        cout << "You are also going!";
    }
}