#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 1e12;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = i * i + j * j;
      double gap = (cost - e * e);
      if (gap < min) {
        min = gap;
      }
    }
    cout << sqrt(min) << endl;
  }
  return 0;
}