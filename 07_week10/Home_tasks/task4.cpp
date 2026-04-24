#include <iostream>
using namespace std;

int projectTimeCalculation(int days, int workers);

int main()
{
  int neededHours, days, workers;

  cin >> neededHours;
  cin >> days;
  cin >> workers;

  int availableHours = projectTimeCalculation(days, workers);

  if (availableHours >= neededHours)
  {
    cout << "Yes!" << availableHours - neededHours << " hours left.";
  }
  else
  {
    cout << "Not enough time!" << neededHours - availableHours << " hours needed.";
  }
}

int projectTimeCalculation(int days, int workers)
{
  float workingDays = days - (0.10 * days);

  float totalHours = workingDays * 10 * workers;

  // round down
  int finalHours = totalHours;
  return finalHours;
}