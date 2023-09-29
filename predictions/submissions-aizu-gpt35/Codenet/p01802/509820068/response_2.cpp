#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int d, e;
  while (cin >> d >> e) {
    if (d == 0 && e == 0)
      break;
    double min = 100000;
    for (int i = 0; i <= d; i++) {
      if (i + d < e) continue;
      double j = sqrt(d * d - i * i);
      double cost = sqrt(i * i + j * j);
      double gap = abs(cost - e);
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}