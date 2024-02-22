#include <iostream>
using namespace std;

int main() {
  int inputSeconds;
  int hours, minutes, seconds;

  cout << "Enter the number of seconds: ";
  cin >> inputSeconds;

  // Error handling for negative values or non-integer inputs
  if (inputSeconds < 0 || cin.fail()) {
    cout << "Invalid input." << endl;
    return 0;
  }

  hours = inputSeconds / 3600;
  inputSeconds %= 3600;
  minutes = inputSeconds / 60;
  seconds = inputSeconds % 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;

  return 0;
}