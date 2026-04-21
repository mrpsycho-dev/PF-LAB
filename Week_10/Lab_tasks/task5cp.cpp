#include <iostream>
#include <cmath>
using namespace std;

void solveQuadratic(float a, float b, float c);

int main()
{
  float a, b, c;

  cout << "Enter values of a, b, c: ";
  cin >> a >> b >> c;

  solveQuadratic(a, b, c);

  return 0;
}

void solveQuadratic(float a, float b, float c)
{
  float discriminant = (b * b) - (4 * a * c);

  cout << "\nDiscriminant = " << discriminant << endl;

  if (discriminant > 0)
  {
    float root1 = (-b + sqrt(discriminant)) / (2 * a);
    float root2 = (-b - sqrt(discriminant)) / (2 * a);

    cout << "Two real and distinct roots:\n";
    cout << "Root 1 = " << root1 << endl;
    cout << "Root 2 = " << root2 << endl;
  }
  else if (discriminant == 0)
  {
    float root = -b / (2 * a);

    cout << "One real root (repeated):\n";
    cout << "Root = " << root << endl;
  }
  else
  {
    float realPart = -b / (2 * a);
    float imaginaryPart = sqrt(-discriminant) / (2 * a);

    cout << "Complex roots:\n";
    cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i\n";
    cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i\n";
  }
}