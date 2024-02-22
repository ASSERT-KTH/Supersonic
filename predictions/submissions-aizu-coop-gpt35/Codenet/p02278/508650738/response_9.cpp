#include <bits/stdc++.h>
using namespace std;
#define int long long

struct QuickFind {
  vector<int> r, p;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
    }
  }
  bool same(int x, int y) { return p[x] == p[y]; }
  void unite(int x, int y) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (r[x] < r[y])
      swap(x, y);
    r[x] += r[y];
    p[y] = x;
  }
};

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  map<int, int> p, q;
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);
  int ans = 0;
  int m = a[qf.p[0]];
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    int k = qf.r[qf.p[i]];
    if (qf.p[i] != i || k == 1)
      continue;
    tmp += a[i];
    m = min(m, a[i]);
    ans += tmp;
  }
  ans += m * (n - 2);
  cout << ans << endl;
  return 0;
}