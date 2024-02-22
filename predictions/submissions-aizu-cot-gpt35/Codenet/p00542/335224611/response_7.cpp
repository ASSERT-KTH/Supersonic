#include <iostream>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  
  int min_val = (a < b) ? ((a < c) ? ((a < d) ? a : d) : ((c < d) ? c : d)) : ((b < c) ? ((b < d) ? b : d) : ((c < d) ? c : d));
  int max_val = (e > f) ? e : f;
  
  int ans = a + b + c + d - min_val + max_val;
  
  std::cout << ans << std::endl;
  return 0;
}