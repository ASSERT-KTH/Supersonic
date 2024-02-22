#include <iostream>
#include <algorithm>

int main() {
  int a[4], e, f;

  for(int i = 0; i < 4; i++) {
      std::cin >> a[i];
  }
  
  std::cin >> e >> f;
  
  int ans = std::accumulate(a, a+4, 0);
  ans = ans - *std::min_element(a, a+4);
  ans = ans + std::max(e, f);
  
  std::cout << ans << std::endl;
  
  return 0;
}