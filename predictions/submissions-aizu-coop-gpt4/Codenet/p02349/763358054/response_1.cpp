#include <cstdio>
#define ll long long

ll S[100005];
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
      for (int i = k, j; i > 0; i -= j) {
        j = i & -i; // Store the result of 'i & -i' in 'j'
        ans += S[i];
      }
      printf("%lld\n", ans);
    } else {
      int s, t, x;
      scanf("%d %d %d", &s, &t, &x);
      for (int i = s, j; i <= n; i += j) {
        j = i & -i; // Store the result of 'i & -i' in 'j'
        S[i] += x;
      }
      for (int i = t + 1, j; i <= n; i += j) {
        j = i & -i; // Store the result of 'i & -i' in 'j'
        S[i] -= x;
      }
    }
  }
  return 0;
}