#include <iostream>
using namespace std;

int main() {

    int num, sum = 0;

    cout << "Enter number: ";
    cin >> num;

    while (num > 0) {
    int x = num%10;
        sum = sum + x;
        num /= 10;
    }

    cout << "Digit Sum = " << sum;

    return 0;
}