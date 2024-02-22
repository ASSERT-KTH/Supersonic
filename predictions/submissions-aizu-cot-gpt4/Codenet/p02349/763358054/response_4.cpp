#include <iostream>
#include <cstdio>
#define maxn 100005

long long S[maxn];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  while (q--) {
    bool op;
    scanf("%d", &op);
    if (op) {
      int k, ans = 0;
      scanf("%d", &k);
      for (; k > 0; k -= k & -k)
        ans += S[k];
      printf("%d\n", ans);
    } else {
      int s, t;
      long long x;
      scanf("%d %d %lld", &s, &t, &x);
      for (; s <= n; s += s & -s)
        S[s] += x;
      for (; t + 1 <= n; t += t & -t)
        S[t+1] += -x;
    }
  }

  return 0;
}