#include <iostream>
#include <math.h>
using namespace std;

constexpr double LARGE_NUMBER = 100000;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;
    double min = LARGE_NUMBER;
    for (int i = 0; i <= d; i++) {
      int j = d - i; // directly calculate j
      double cost = sqrt(i * i + j * j);
      double gap = sqrt((cost - e) * (cost - e));
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}