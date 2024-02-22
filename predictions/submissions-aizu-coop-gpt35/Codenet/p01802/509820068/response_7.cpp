#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 100000;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i; // Calculate j based on i
      double gap = sqrt(pow((i * i + j * j) - e * e, 0.5)); // Calculate gap directly
      if (gap < min) {
        min = gap;
      }
    }
    cout << min << endl;
  }
  return 0;
}