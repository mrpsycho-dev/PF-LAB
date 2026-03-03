#include <iostream>
using namespace std;

int main() {
    
    int monthlySalary = 10000;
    int laptopPrice = 50000;
    int advanceMonths = 6;
    
    int advanceAmount = (monthlySalary * 50 / 100) * advanceMonths;
    
    if (advanceAmount >= laptopPrice) {
        cout << "Ali can buy the laptop with advanced salary." << endl;
    }
    else {
        int monthsRequired = laptopPrice / monthlySalary;
        
        cout << "Months required to buy laptop: " << monthsRequired << endl;
    }
    
    return 0;
}