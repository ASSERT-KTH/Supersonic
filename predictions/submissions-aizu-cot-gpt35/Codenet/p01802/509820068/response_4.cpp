#include <iostream>
#include <cmath>

int main() {
  int d;
  while (1) {
    std::cin >> d;
    if (d == 0)
      break;
      
    const double initial_min = 100000;
    double min = initial_min;

    for (int i = 0; i < d; i++) {
      for (int j = i; j <= d - i; j++) {
        if (i + j == d) {
          double cost = std::sqrt(std::pow(i, 2) + std::pow(j, 2));
          double gap = std::abs(cost - d);
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