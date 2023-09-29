#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (cin >> d >> e) {
    if (d == 0 && e == 0)
      break;
    double min_gap = abs(sqrt(d*d + (d-e)*(d-e)) - d);
    for (int i = d; i >= 0; --i) {
      if (i <= e) {
        double gap = abs(sqrt(i*i + (i-e)*(i-e)) - i);
        if (gap < min_gap)
          min_gap = gap;
      }
    }
    cout << min_gap << endl;
  }
  return 0;
}