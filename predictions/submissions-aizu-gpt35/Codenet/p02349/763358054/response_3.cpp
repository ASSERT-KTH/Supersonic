#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

inline int lowbit(int x) {
  return x & -x;
}

int query(int k) {
  int ans = 0;
  for (int i = k; i > 0; i -= lowbit(i))
    ans += S[i];
  return ans;
}

void update(int s, int x) {
  for (int i = s; i <= n; i += lowbit(i))
    S[i] += x;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(i, x - S[i-1]);
  }
  while (q--) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      cout << query(k) << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      update(s, x);
      update(t+1, -x);
    }
  }
  return 0;
}