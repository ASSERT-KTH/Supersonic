#include <iostream>
using namespace std;

int main() {
  int inputSeconds;
  cin >> inputSeconds;

  int hours = inputSeconds / 3600;
  int minutes = (inputSeconds % 3600) / 60;
  int seconds = inputSeconds % 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;

  return 0;
}