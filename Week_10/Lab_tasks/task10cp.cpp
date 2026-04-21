#include <iostream>
using namespace std;

string numberToText(int num)
{
  string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five",
                   "Six", "Seven", "Eight", "Nine"};

  string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  string tens[] = {"", "", "Twenty", "Thirty", "Forty",
                   "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  if (num >= 1 && num <= 9)
  {
    return ones[num];
  }
  else if (num >= 10 && num <= 19)
  {
    return teens[num - 10];
  }
  else
  {
    int t = num / 10;
    int o = num % 10;

    return tens[t] + ones[o];
  }
}

int main()
{
  int number;

  cout << "Enter a number (0-99): ";
  cin >> number;

  string result = numberToText(number);

  cout << result;

  return 0;
}