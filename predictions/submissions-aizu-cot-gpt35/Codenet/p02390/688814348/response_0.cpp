#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int hours = S / 3600;
  int remainingSeconds = S % 3600;
  int minutes = remainingSeconds / 60;
  int seconds = remainingSeconds % 60;
  cout << hours << ":" << minutes << ":" << seconds << endl;
}