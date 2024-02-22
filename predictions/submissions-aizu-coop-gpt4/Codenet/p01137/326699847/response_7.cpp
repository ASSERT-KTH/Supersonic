#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;

int main(void) {
  // Precompute squares and cubes
  vector<int> squares(101), cubes(101);
  for (int i = 0; i <= 100; ++i) {
    squares[i] = i * i;
    cubes[i] = i * i * i;
  }

  int e;
  while (scanf("%d", &e), e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = cubes[z];
      if (val > e)
        continue;
      int eMinusVal = e - val;
      for (int y = sqrt(eMinusVal); y >= 0; --y) {
        int val2 = val + squares[y];
        if (val2 > e)
          continue;
        m = min(m, (eMinusVal - squares[y]) + y + z);
      }
    }
    printf("%d\n", m);
  }
  return EXIT_SUCCESS;
}