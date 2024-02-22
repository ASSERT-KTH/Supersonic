#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdio>

int main() {
  int a, b, c, d, e, f;
  std::scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  
  long long ans = a + b + c + d - std::min({a, b, c, d}) + e + f;
  
  std::printf("%lld\n", ans);
  
  return 0;
}