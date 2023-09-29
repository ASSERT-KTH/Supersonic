#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  while (q--) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      ll ans = 0;
      while (k > 0) {
        ans += S[k];
        k -= k & -k;
      }
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      while (s <= n) {
        S[s] += x;
        s += s & -s;
      }
      while (t <= n) {
        S[t] -= x;
        t += t & -t;
      }
    }
  }
}