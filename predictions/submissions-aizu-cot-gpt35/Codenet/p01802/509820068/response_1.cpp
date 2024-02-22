#include <iostream>
#include <cmath>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    if (d == 0 && e == 0)
      break;

    double min_gap = 100000;
    double cost = 0;

    for (int i = 0; i <= d; i++) {
      cost = std::sqrt(i * i + d * d);
      double gap = std::abs(cost - e);
      if (gap < min_gap) {
        min_gap = gap;
      }
    }

    std::cout << min_gap << std::endl;
  }

  return 0;
}