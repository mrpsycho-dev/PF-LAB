#include <iostream>
using namespace std;

int main() {

    int a, b, gcd = 1;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    for (int i = min(a,b); i>=1; i--) {

        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    int lcm = (a * b) / gcd;

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm;

    return 0;
}