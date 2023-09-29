#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (cin >> d >> e) {
    if (d == 0 && e == 0)
      break;
    double min_gap = 1e9;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = abs(cost - e);
      if (gap < min_gap) {
        min_gap = gap;
      }
      if (i * i > e * e)
        break;
    }
    cout << min_gap << endl;
  }
  return 0;
}