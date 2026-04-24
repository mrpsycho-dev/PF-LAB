#include <iostream>
using namespace std;

string timeTravel(int hour, int minute)
{
  minute += 15;

  if (minute >= 60)
  {
    minute -= 60;
    hour += 1;
  }

  if (hour >= 24)
  {
    hour = 0;
  }

  return to_string(hour) + ":" + to_string(minute);
}

int main()
{
  int hour, minute;

  cout << "Enter hour: ";
  cin >> hour;

  cout << "Enter minutes: ";
  cin >> minute;

  // FUNCTION CALL
  string result = timeTravel(hour, minute);

  cout << result;

  return 0;
}