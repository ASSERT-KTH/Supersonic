#include <iostream>
#include <cmath> // Use <cmath> instead of <math.h>

int main() {
  int d, e;
  while (true) {
    std::cin >> d >> e;
    if (d == 0 && e == 0)
      break;

    int minGap = 100000;
    for (int i = 0; i <= d; i++) {
      for (int j = d - i; j <= d; j++) {
        if (i + j == d) {
          int cost = std::sqrt(i * i + j * j);
          int gap = std::abs(cost - e);
          if (gap < minGap) {
            minGap = gap;
          }
        }
      }
    }
    std::cout << minGap << std::endl;
  }
  return 0;
}