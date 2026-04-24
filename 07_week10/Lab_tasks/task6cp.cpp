#include <iostream>
using namespace std;

string checkAlphabetCase(char ch)
{
  if (ch == 'A')
  {
    return "You have entered Capital A";
  }
  else
  {
    return "You have entered small A";
  }
}

int main()
{
  char input;

  cout << "Enter an alphabet (A or a): ";
  cin >> input;

  string result = checkAlphabetCase(input);

  cout << result;

  return 0;
}