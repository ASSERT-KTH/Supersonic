#include <iostream>
int main() {
  int x, y;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> x;
  y = x * x * x;
  std::cout << y << "\n";
  return 0;
}