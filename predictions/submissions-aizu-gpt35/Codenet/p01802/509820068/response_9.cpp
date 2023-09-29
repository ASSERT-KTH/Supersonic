#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0) break;
    double min = 100000;
    int start = max(e, d - e);
    int end = min(d, e);
    for (int i = start; i <= end; i++) {
      double cost = sqrt(d * d + i * i);
      double gap = abs(cost - e);
      if (gap < min) {
        min = gap;
      }
    }
    cout.precision(3);
    cout << fixed << min << endl;
  }
  return 0;
}