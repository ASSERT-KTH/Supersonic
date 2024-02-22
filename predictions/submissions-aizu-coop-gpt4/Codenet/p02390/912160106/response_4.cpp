#include <iostream>
using namespace std;

int main() {
  int seconds;
  cin >> seconds;

  int h = seconds / 3600;
  seconds %= 3600;

  int m = seconds / 60;
  seconds %= 60;

  cout << h << ":" << m << ":" << seconds << endl;
  return 0;
}