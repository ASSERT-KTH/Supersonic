#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int maxn = 100005;
ll S[maxn];
int n, q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      ll ans = 0;
      for (int i = k; i > 0; i -= i & -i)
        ans += S[i];
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      for (int i = s; i <= n; i += i & -i)
        S[i] += x;
      for (int i = t + 1; i <= n; i += i & -i)
        S[i] -= x;
    }
  }
}