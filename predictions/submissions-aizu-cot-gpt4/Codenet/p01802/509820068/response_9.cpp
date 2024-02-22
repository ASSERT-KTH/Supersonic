#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, e;
  while (1) {
    cin >> d >> e;
    double min = 100000 * 100000; // min is now the square of minimum gap
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double costSquare = i * i + j * j;
      double gapSquare = (costSquare - e * e) * (costSquare - e * e);
      if (gapSquare < min) {
        min = gapSquare;
      }
    }
    cout << sqrt(min) << endl; // Take square root here when printing
  }
  return 0;
}