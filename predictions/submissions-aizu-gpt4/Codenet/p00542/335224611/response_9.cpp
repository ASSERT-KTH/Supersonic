#include <algorithm>
#include <iostream>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  int min_val = std::min({a, b, c, d});
  int max_val = std::max(e, f);
  int ans = a + b + c + d - min_val + max_val;
  std::cout << ans << '\n';
  return 0;
}