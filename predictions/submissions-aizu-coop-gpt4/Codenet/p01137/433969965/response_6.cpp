#include <iostream>
#include <cmath>
#include <climits>
#include <cstdio>

typedef long long ll;

const int MAX_INT = INT_MAX;

int main() {
  int e;
  while (scanf("%d", &e), e) {
    int ans = MAX_INT;
    int limitZ = cbrt(e);
    for (int z = 0; z <= limitZ; ++z) {
      int limitY = sqrt(e - z * z * z);
      for (int y = 0; y <= limitY; ++y) {
        int temp = e - (y * y + z * z * z) + y + z;
        if(temp < ans){
          ans = temp;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}