#include <iostream>
#include <algorithm>

const int inf = 1000000000;

int main() {
  int e;
  while(std::cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y + z * z * z <= e; ++y) {
        int tmp = y * y + z * z * z;   //calculate once and store
        int x = e - tmp;
        ans = std::min(ans, x + y + z);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}