#include <iostream>

int main() {
  double re1, im1, re2, im2;
  std::cin >> re1 >> im1 >> re2 >> im2;
  
  double absDiff = std::sqrt((re1 - re2) * (re1 - re2) + (im1 - im2) * (im1 - im2));
  std::cout.precision(5);
  std::cout << std::fixed << absDiff << std::endl;
  
  return 0;
}