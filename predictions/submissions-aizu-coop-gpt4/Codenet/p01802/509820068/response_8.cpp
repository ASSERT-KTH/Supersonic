#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 1e5;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = abs(cost - e); // using abs instead of sqrt((cost - e) * (cost - e))
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}