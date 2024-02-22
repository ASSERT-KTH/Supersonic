#include <iostream>
#include <cmath>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  int t = 0;
  int sqrt_c = std::sqrt(c);

  for (int s = a; s <= sqrt_c; s++) {
    if (c % s == 0) {
      t++;
      if (s != c / s) {
        t++;
      }
    }
  }

  std::cout << t << std::endl;
  return 0;
}