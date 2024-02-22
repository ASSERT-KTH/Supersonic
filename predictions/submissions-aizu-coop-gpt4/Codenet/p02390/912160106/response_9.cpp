#include <iostream>
using namespace std;

int main() {
  int inputSeconds;
  cin >> inputSeconds;

  int hours = inputSeconds / 3600; // calculate hours
  inputSeconds %= 3600; // update inputSeconds with remaining seconds after calculating hours

  int minutes = inputSeconds / 60; // calculate minutes
  inputSeconds %= 60; // update inputSeconds with remaining seconds after calculating minutes

  // output the result
  cout << hours << ":" << minutes << ":" << inputSeconds << endl;
  
  return 0;
}