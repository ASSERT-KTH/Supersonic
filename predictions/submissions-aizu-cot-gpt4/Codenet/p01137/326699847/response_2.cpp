#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int e;
  while (scanf("%d", &e) == 1 && e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      for (int y = sqrt(e - val); y >= 0; --y) {
        val += y * y;
        if (val > e)
          continue;
        m = min(m, (e - val) + y + z);
      }
    }
    printf("%d\n", m);
  }
  return 0;
}