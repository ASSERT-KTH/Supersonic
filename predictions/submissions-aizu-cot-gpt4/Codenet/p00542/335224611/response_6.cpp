#include <iostream>
#include <algorithm>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;

  int smallest_ab = std::min(a, b);
  int smallest_cd = std::min(c, d);
  int largest_ef = std::max(e, f);

  int ans = a + b + c + d - std::min(smallest_ab, smallest_cd) + largest_ef;

  std::cout << ans << '\n';

  return 0;
}