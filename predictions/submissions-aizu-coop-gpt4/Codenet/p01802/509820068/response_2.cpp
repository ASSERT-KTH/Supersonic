#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 100000;
    if (d == 0 && e == 0)
      break;
    int half_d = d / 2;
    for (int i = 0; i <= half_d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = cost - e;
      gap = gap * gap; // square the difference instead of taking the absolute value
      if (gap < min) {
        min = gap;
      }
    }
    cout << sqrt(min) << endl;  // output the square root of the minimum gap
  }
  return 0;
}