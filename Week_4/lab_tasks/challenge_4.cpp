#include <iostream>
using namespace std;

int main() {
    char a;
    
    cout << "Enter a character: ";
    cin >> a;

    if (a >= '0' && a <= '9') {
        cout << "It is a number.";
    }
    else if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
             a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') {
        cout << "It is a vowel.";
    }
    else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        cout << "It is a consonant.";
    }

    return 0;
}