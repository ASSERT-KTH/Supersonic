#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int e;
  while (scanf("%d", &e), e) {
    int ans = 1000000000;
    int maxZ = cbrt(e);
    for (int z = 0; z <= maxZ; ++z) {
      int maxY = sqrt(e - z * z * z);
      for (int y = 0; y <= maxY; ++y) {
        int x = e - y * y - z * z * z;
        ans = min(ans, x + y + z);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}