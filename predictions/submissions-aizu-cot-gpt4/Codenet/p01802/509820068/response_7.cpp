#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  double min = 100000;

  while (cin >> d >> e, d || e) {
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap_squared = (cost - e) * (cost - e);
      if (gap_squared < min * min) {
        min = sqrt(gap_squared);
      }
    }
    cout << min << endl;
  }

  return 0;
}