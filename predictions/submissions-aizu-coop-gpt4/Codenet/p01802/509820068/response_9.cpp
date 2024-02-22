#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;
    double min_gap = 1e6;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = abs(cost - e);
      min_gap = min(min_gap, gap);
    }
    cout << min_gap << endl;
  }
  return 0;
}