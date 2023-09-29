#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn << 1];
int n, q;
inline int lowbit(int x) { return x & -x; } // added inline function
int main() {
  ios_base::sync_with_stdio(false); // added
  cin.tie(NULL); // added
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      int ans = 0;
      for (int i = k; i > 0; i -= lowbit(i)) // replaced with inline function
        ans += S[i];
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      for (int i = s; i <= n; i += lowbit(i)) // replaced with inline function
        S[i] += x;
      for (int i = t + 1; i <= n; i += lowbit(i)) // replaced with inline function
        S[i] += -x;
    }
  }
}