#include <iostream>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int x, y;
  std::cin >> x;

  if(std::abs(x) <= 1290) {
    y = x << 3; // Faster than multiplication for smaller numbers
  } else {
    y = x * x * x; // Safe for larger numbers
  }

  std::cout << y << '\n';

  return 0;
}