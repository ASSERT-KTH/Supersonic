#include <algorithm>
#include <iostream>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  int ans = a + b + c + d - std::min({a, b, c, d}) + std::max(e, f);
  std::cout << ans << '\n';
  return 0;
}