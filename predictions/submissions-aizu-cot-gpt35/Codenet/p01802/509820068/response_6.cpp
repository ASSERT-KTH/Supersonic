#include <iostream>
#include <cmath>
using namespace std;

int main() {
  while (1) {
    int d, e;
    cin >> d >> e;

    if (d == 0 && e == 0)
      break;

    double min = 0;
    for (int i = 0; i <= d/2; i++) {
      for (int j = i; j <= d/2; j++) {
        if (i + j == d) {
          double cost = sqrt(i * i + j * j);
          double gap = abs(cost - e);
          if (gap < min) {
            min = gap;
          }
        }
      }
    }

    cout << min << endl;
  }

  return 0;
}