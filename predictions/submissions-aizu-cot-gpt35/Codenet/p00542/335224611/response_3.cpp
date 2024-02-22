#include <iostream>

int main() {
  int a, b, d, e;
  std::cin >> a >> b >> d >> e;
  
  int ans = a + b + d - std::min({a, b, d}) + std::max(e, d);
  std::cout << ans << std::endl;
  
  return 0;
}