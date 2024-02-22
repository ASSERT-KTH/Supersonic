#include <iostream>
using namespace std;

const int maxn = 100005;
int S[maxn];
int n, q;

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    int op;
    scanf("%d", &op);
    if (op) {
      int k;
      scanf("%d", &k);
      int ans = 0;
      for (int i = k; i > 0; i &= i - 1)
        ans += S[i];
      printf("%d\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);
      for (int i = s; i <= n; i += i & -i)
        S[i] += x;
      for (int i = t; i <= n; i += i & -i)
        S[i] -= x;
    }
  }

  return 0;
}