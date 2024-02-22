#include <iostream>
#include <algorithm>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  int minimum = std::min(std::min(a, b), std::min(c, d));
  int maximum = std::max(e, f);
  int ans = a + b + c + d + e + f - minimum + maximum;
  std::cout << ans << std::endl;
  return 0;
}