#include <iostream>

int main() {
  short a, b, e, f;
  std::cin >> a >> b >> e >> f;

  short minVal = std::min(std::min(a, b), std::min(a, f));
  short sum = a + b + e + f;
  short ans = sum - minVal;

  std::cout << ans << std::endl;
  return 0;
}