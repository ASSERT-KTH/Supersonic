#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;
    double min_gap = INFINITY;
    for (int i = 0; i <= d; i++) {
      double cost = i * i + d * d;
      double gap = fabs(cost - e * e);
      if (gap < min_gap) {
        min_gap = gap;
      }
    }
    cout << sqrt(min_gap) << endl;
  }
  return 0;
}