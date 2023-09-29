#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (cin >> d >> e) {
    if (d == 0 && e == 0) {
      break;
    }
    double min_gap = e, max_gap = 0;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = fabs(cost - e);
      if (gap < min_gap) {
        min_gap = gap;
      } else if (gap > max_gap) {
        max_gap = gap;
      }
    }
    cout << min_gap << endl;
  }
  return 0;
}