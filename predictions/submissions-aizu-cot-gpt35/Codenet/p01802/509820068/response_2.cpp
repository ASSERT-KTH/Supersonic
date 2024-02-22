#include <iostream>
#include <cmath>
#include <vector>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    double min = 100000;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      for (int j = i; j <= d; j++) {
        if (i + j == d) {
          double cost = std::sqrt(i * i + j * j);
          double gap = std::abs(cost - e);
          min = std::min(min, gap);
        }
      }
    }
    std::cout << min << std::endl;
  }
  return 0;
}