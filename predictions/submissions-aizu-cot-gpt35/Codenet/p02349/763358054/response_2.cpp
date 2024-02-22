#include <iostream>
using namespace std;

const int maxn = 100005;
int S[maxn];
int n, q;

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    bool op;
    scanf("%d", &op);
    if (op) {
      int k;
      scanf("%d", &k);
      int ans = 0;
      for (int j = k; j > 0; j -= j & -j)
        ans += S[j];
      printf("%d\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);
      for (int j = s; j <= n; j += j & -j)
        S[j] += x;
      for (int j = t + 1; j <= n; j += j & -j)
        S[j] += -x;
    }
  }
  return 0;
}