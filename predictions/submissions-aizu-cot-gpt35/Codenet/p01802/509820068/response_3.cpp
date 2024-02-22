#include <iostream>
#include <cmath>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    double min = 100000;
    if (!(d || e))
      break;
    for (int i = 0; i <= d / 2; i++) {
      for (int j = i; j <= d - i; j++) {
        if (i + j == d) {
          double costSquared = i * i + j * j;
          double gapSquared = (costSquared - e) * (costSquared - e);
          if (gapSquared < min * min) {
            min = std::sqrt(gapSquared);
          }
        }
      }
    }
    std::cout << min << std::endl;
  }
  return 0;
}