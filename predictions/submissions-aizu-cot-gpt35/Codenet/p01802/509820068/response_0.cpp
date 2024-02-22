#include <iostream>
#include <cmath>
#include <limits>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    double min = std::numeric_limits<double>::max();
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      for (int j = i; j <= d; j++) {
        if (i + j == d) {
          double cost = std::sqrt(std::pow(i, 2) + std::pow(j, 2));
          double gap = std::abs(cost - e);
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