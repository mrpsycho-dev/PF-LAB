#include <iostream>
using namespace std;

float calculateSalary(float base, int score, int experience);

int main()
{
  float base;
  int score, experience;
  cout << "enter base salary, score, and experience in years: ";
  cin >> base >> score >> experience;

  float finalSalary = calculateSalary(base, score, experience);

  cout << finalSalary;
}

float calculateSalary(float base, int score, int experience)
{
  float bonusPercent;

  if (score >= 90)
  {
    bonusPercent = 0.20;
  }
  else if (score >= 75)
  {
    bonusPercent = 0.10;
  }
  else
  {
    bonusPercent = 0.05;
  }

  // experience bonus
  if (experience >= 5)
  {
    bonusPercent = bonusPercent + 0.05;
  }

  float finalSalary = base + (base * bonusPercent);

  return finalSalary;
}