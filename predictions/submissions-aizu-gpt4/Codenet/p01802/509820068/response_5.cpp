#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (!d && !e)
      break;
    double minGap = 1e5;
    for (int i = 0; i <= d; ++i) {
      double j = d - i;
      double cost = hypot(i, j);
      double gap = abs(cost - e);
      if (gap < minGap) {
        minGap = gap;
      }
    }
    cout << minGap << endl;
  }
  return 0;
}