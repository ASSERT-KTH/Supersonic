#include <iostream>
int main() {
  int x, y;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> x;
  y = x * x * x;
  std::cout << y << "\n";
  return 0;
}