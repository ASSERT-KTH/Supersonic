#include <iostream>
#include <math.h>

int main() {
  int d, e;
  while (1) {
    std::cin >> d >> e;
    double min = 100000;
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double cost = sqrt(i * i + j * j);
      double gap = fabs(cost - e);
      if (gap < min) {
        min = gap;
      }
    }
    std::cout << min << std::endl;
  }
  return 0;
}