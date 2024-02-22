#include <iostream>
#include <cmath>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    double min = std::numeric_limits<double>::infinity();
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      for (int j = i; j <= d; j++) {
        if (i + j == d) {
          int distanceSquared = i * i + j * j;
          double gap = std::abs(std::sqrt(distanceSquared) - e);
          if (gap < min) {
            min = gap;
          }
        }
      }
    }
    std::cout << min << std::endl;
  }
  return 0;
}