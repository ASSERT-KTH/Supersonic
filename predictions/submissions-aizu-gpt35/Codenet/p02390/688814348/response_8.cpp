#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int hours = S / 3600;
  S %= 3600;
  int minutes = S / 60;
  int seconds = S % 60;
  cout << hours << ":" << minutes << ":" << seconds << endl;
}