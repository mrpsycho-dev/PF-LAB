#include <iostream>
using namespace std;

int main() {

    int choice;

    while (true) {

        cout << "1.Add Books\n";
        cout << "2.View Books\n";
        cout << "3.Borrow Books\n";
        cout << "4.Return Books\n";
        cout << "5.Exit\n";

        cin >> choice;

        if (choice == 1)
            cout << "Book added.\n";

        else if (choice == 2)
            cout << "Showing books.\n";

        else if (choice == 3)
            cout << "Book borrowed.\n";

        else if (choice == 4)
            cout << "Book returned.\n";

        else if (choice == 5) {
            cout << "Exiting Library System.\n";
            return 0;
        }

        else
            cout << "Invalid choice\n";
    }

    return 0;
}