#include <iostream>
int main() {
  int a, b;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> a >> b;
  int mul = a * b;
  std::cout << mul << " " << (mul << 1) - (a + b) << "\n";
  return 0;
}