#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int a, b;
  std::cin >> a >> b;

  std::cout << a * b << " " << 2 * (a + b) << '\n';

  return 0;
}