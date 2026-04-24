#include <iostream>
#include <string>
using namespace std;

string calculatePoolState(int V, int P1, int P2, float H)
{
  float totalWater = (P1 + P2) * H;

  // Pool not overflowing
  if (totalWater <= V)
  {
    int poolPercent = (totalWater / V) * 100;
    int pipe1Percent = (P1 * H / totalWater) * 100;
    int pipe2Percent = (P2 * H / totalWater) * 100;

    return "The pool is " + to_string(poolPercent) + "% full. Pipe 1: " +
           to_string(pipe1Percent) + "%. Pipe 2: " +
           to_string(pipe2Percent) + "%.";
  }
  // Pool overflowing
  else
  {
    float overflow = totalWater - V;

    return "For " + to_string(H) + " hours the pool overflows with " +
           to_string(overflow) + " liters.";
  }
}

int main()
{
  int V, P1, P2;
  float H;

  cout << "Enter pool volume (V): ";
  cin >> V;

  cout << "Enter pipe 1 flow rate (P1): ";
  cin >> P1;

  cout << "Enter pipe 2 flow rate (P2): ";
  cin >> P2;

  cout << "Enter hours (H): ";
  cin >> H;

  string result = calculatePoolState(V, P1, P2, H);

  cout << result << endl;

  return 0;
}