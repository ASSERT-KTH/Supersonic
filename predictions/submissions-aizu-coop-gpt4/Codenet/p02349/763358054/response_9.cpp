#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      int ans = 0;
      for (int j = k; j > 0; j -= j & -j)
        ans += S[j];
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      for (int j = s, u = j & -j; j <= n; j += u, u = j & -j)
        S[j] += x;
      for (int j = t + 1, u = j & -j; j <= n; j += u, u = j & -j)
        S[j] -= x;
    }
  }
}