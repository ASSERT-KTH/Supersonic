#include <bits/stdc++.h>
using namespace std;
#define int long long

struct QuickFind {
  vector<int> r, p, v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i] = i;
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
    for (int i = 0; i < r[y]; i++) {
      p[v[y + i]] = x;
    }
    v[x] = v[y];
    v[y] = 0;
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
  
  vector<int> group_sizes(n, 0);
  vector<int> group_minimum(n, 0);
  for (int i = 0; i < n; i++) {
    int group_id = qf.p[i];
    group_sizes[group_id]++;
    int element_value = a[qf.v[group_id]];
    if (group_minimum[group_id] == 0 || element_value < group_minimum[group_id]) {
      group_minimum[group_id] = element_value;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int group_id = qf.p[i];
    int k = group_sizes[group_id];
    if (group_id != i || k == 1)
      continue;
    int m = group_minimum[group_id];
    int tmp = k * m;
    ans += min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }
  cout << ans << endl;
  return 0;
}