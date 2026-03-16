#include <iostream>
using namespace std;

int main() {

    int choice;
    double a, b;

    while (true) {

        cout << "\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Clear Screen\n6.Exit\n";
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting Calculator. Goodbye!";
            break;
        }

        if (choice == 5) {
            cout << "Screen cleared.\n";
            continue;
        }

        cout << "Enter two numbers: ";
        cin >> a >> b;

        if (choice == 1)
            cout << "Result = " << a + b << endl;

        else if (choice == 2)
            cout << "Result = " << a - b << endl;

        else if (choice == 3)
            cout << "Result = " << a * b << endl;

        else if (choice == 4) {

            if (b == 0)
                cout << "Cannot divide by zero\n";
            else
                cout << "Result = " << a / b << endl;
        }
    }

    return 0;
}