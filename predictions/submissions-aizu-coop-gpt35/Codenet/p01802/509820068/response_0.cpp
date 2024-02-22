#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int d, e;
  while (true) {
    cin >> d >> e;
    if (d == 0 && e == 0)
      break;

    double minDistance = 100000;
    for (int i = 0; i <= d; i++) {
      for (int j = 0; j <= d - i; j++) {
        if (i + j == d) {
          double cost = pow(i, 2) + pow(j, 2);
          if (cost < minDistance) {
            minDistance = cost;
          }
        }
      }
    }
    cout << sqrt(minDistance) << endl;
  }
  return 0;
}