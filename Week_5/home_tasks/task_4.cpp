#include <iostream>
using namespace std;

int main() {

    int num, sum = 0;

    for(int i=0; i<5;i++) {
        cout << "Enter number: ";
        cin >> num;

       

        sum += num;
    }

    cout << "Sum = " << sum;

    return 0;
}