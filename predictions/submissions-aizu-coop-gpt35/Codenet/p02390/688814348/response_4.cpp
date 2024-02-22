#include <iostream>
using namespace std;

int main(void) {
  int S;
  cin >> S;

  // Input validation
  if (S < 0) {
    cout << "Invalid input" << endl;
    return 0;
  }

  int hours = S / 3600;
  int minutes = (S % 3600) / 60;
  int seconds = (S % 3600) % 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;

  return 0;
}