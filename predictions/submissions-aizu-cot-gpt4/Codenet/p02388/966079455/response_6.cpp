#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int x, y;
  std::cin >> x;
  y = x * x * x;
  std::cout << y << "\n";
  return 0;
}