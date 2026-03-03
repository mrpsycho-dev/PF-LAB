#include <iostream>
#include <cmath>
using namespace std;

int main() {

 int holidays, totalDays, workingDays, normMinutes, playMinutes, difference, hours, minutes;

 totalDays = 365;
 normMinutes = 30000;

    
 cout << "Holidays: ";
 cin >> holidays;
 workingDays = totalDays - holidays;
 playMinutes = (workingDays * 63) + (holidays * 127);
 difference = abs(normMinutes - playMinutes);
 hours = difference / 60;
 minutes = difference % 60;

    
 if (playMinutes <= normMinutes) {
    cout << "Tom sleeps well" << endl;
    cout << hours << " hours and "
             << minutes << " minutes less for play";
 } else {
    cout << "Tom will run away" << endl;
    cout << hours << " hours and " << minutes << " minutes for play";
}

return 0;
};
