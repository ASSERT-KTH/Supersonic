#include <iostream>
using namespace std;

int main() {
  int input;
  int hours, minutes, seconds;

  // Read the input value
  cin >> input;

  // Calculate hours, minutes, and seconds
  hours = input / 3600;
  input %= 3600;
  minutes = input / 60;
  seconds = input % 60;

  // Output the result
  cout << hours << ":" << minutes << ":" << seconds << endl;

  return 0;
}