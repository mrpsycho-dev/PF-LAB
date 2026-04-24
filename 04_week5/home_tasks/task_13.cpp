#include <iostream>
using namespace std;

int main() {

    int age;
    int toyPrice;
    double washingPrice;

    cin >> age;
    cin >> washingPrice;
    cin >> toyPrice;

    int toys = 0;
    double money = 0;
    int evenMoney = 10;

    for (int i = 1; i <= age; i++) {

        if (i % 2 == 0) {
            money += evenMoney - 1;  
            evenMoney += 10;
        }
        else {
            toys++;
        }
    }

    money += toys * toyPrice;

    if (money >= washingPrice) {
        cout << "Yes! " << money - washingPrice;
    }
    else {
        cout << "No! " << washingPrice - money;
    }

    return 0;
}