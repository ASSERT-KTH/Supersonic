#include <iostream>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;

  int ans = a + b + c + d - *std::min_element({a, b, c, d}) + *std::max_element({e, f});

  std::cout << ans << std::endl;
  return 0;
}