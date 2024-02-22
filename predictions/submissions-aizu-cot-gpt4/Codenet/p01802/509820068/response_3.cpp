#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = numeric_limits<double>::max();
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = fabs(cost - e);
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}