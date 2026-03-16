#include <iostream>
using namespace std;

int main() {

    int num, digit, count = 0;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter digit: ";
    cin >> digit;

    while (num > 0) {

        int x = num % 10;

        if (x == digit) {
            count++;
        }

        num /= 10;
    }

    cout << "Frequency = " << count;

    return 0;
}