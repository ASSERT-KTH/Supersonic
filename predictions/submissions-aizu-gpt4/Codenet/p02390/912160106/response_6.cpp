#include <iostream>
using namespace std;
int main() {
  int input_seconds;
  cin >> input_seconds;
  int hours = input_seconds / 3600;
  int minutes = (input_seconds % 3600) / 60;
  int seconds = input_seconds % 60;
  cout << hours << ":" << minutes << ":" << seconds << endl;
  return 0;
}