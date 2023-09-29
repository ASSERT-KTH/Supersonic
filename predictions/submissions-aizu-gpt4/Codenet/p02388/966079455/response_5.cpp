#include <iostream>
int main() {
  int x;
  long long y;
  std::cin >> x;
  y = static_cast<long long>(x) * x * x;
  std::cout << y << "\n";
  return 0;
}