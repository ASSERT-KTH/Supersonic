#include <bits/stdc++.h>
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
      int ans = 0;
      for (int i = k, d; i > 0; i -= d) {
        d = i & -i;
        ans += S[i];
      }
      printf("%d\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);
      for (int i = s, d; i <= n; i += d) {
        d = i & -i;
        S[i] += x;
      }
      for (int i = t + 1, d; i <= n; i += d) {
        d = i & -i;
        S[i] += -x;
      }
    }
  }
}