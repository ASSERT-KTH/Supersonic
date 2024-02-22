#include <bits/stdc++.h>
using namespace std;
#define int long long
struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.reserve(size);
    p.reserve(size);
    v.reserve(size);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i].reserve(1);
      v[i][0] = i;
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
    for (auto i : v[y]) { // use iterator, not subscript
      p[i] = x;
      v[x].push_back(i);
    }
    v[y].clear();
  }
};
signed main() {
  int n;
  scanf("%lld", &n);
  vector<int> a(n);
  for (int &i : a) // use iterator, not subscript
    scanf("%lld", &i);
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
  for (int i = 0; i < n; i++) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
      continue;
    int m = a[qf.v[i][0]];
    int tmp = 0;
    for (auto j : qf.v[i]) { // use iterator, not subscript
      tmp += a[j];
      m = min(m, a[j]);
    }
    ans += min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }
  printf("%lld\n", ans);
  return 0;
}