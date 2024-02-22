#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    bool op;
    scanf("%d", &op);
    if (op) {
      int k;
      scanf("%d", &k);
      ll ans = 0;
      for (int i = k; i > 0; i -= i & -i)
        ans += S[i];
      printf("%lld\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);
      for (int i = s; i <= t; i += i & -i)
        S[i] += x;
      for (int i = t + 1; i <= n + 1; i += i & -i)
        S[i] += -x;
    }
  }
  return 0;
}