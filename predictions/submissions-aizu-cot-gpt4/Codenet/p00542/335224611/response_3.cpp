#include <iostream>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  
  int min_val = std::min(std::min(a, b), std::min(c, d));
  int max_val = std::max(e, f);
  
  int ans = a + b + c + d - min_val + max_val;
  
  std::cout << ans << '\n';
  
  return 0;
}