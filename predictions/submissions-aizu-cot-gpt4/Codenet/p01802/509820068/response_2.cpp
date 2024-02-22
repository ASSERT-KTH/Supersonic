#include <iostream>
#include <math.h>
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
      double cost_sq = i * i + j * j;
      double gap_sq = (cost_sq - e * e) * (cost_sq - e * e);
      if (gap_sq < min) {
        min = gap_sq;
      }
    }
    cout << sqrt(min) << endl;
  }
  return 0;
}