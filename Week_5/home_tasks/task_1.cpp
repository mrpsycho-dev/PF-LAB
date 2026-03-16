#include <iostream>
using namespace std;

int main() {
    char ch;

    while (true) {
        cout << "I am happy" << endl;
        cout << "Enter n to stop: ";
        cin >> ch;

        if (ch == 'n') {
            break;
        }
    }

    return 0;
}