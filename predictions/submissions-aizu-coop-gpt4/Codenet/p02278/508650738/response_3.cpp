#include <bits/stdc++.h>
using namespace std;

#define int long long

struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;

  QuickFind(int size) { init(size); }

  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i].push_back(i);
    }
  }

  bool same(int x, int y) { return p[x] == p[y]; }

  void unite(int x, int y) {
    x = p[x];
    y = p[y];
    if (x == y) return;
    if (r[x] < r[y]) swap(x, y);
    r[x] += r[y];
    for (int i : v[y]) {
      p[i] = x;
      v[x].push_back(i);
    }
    v[y].clear();
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b = a; 
  sort(b.begin(), b.end());

  unordered_map<int, int> p, q;
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }

  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (qf.p[i] != i || qf.v[i].size() == 1)
      continue;
    int m = a[qf.v[i][0]];
    int tmp = accumulate(qf.v[i].begin(), qf.v[i].end(), 0LL, [&](int sum, int j){ return sum + a[j]; });
    for (int j : qf.v[i]) {
      m = min(m, a[j]);
    }
    ans += min(tmp + m * (qf.v[i].size() - 2), tmp + m + b[0] * (qf.v[i].size() + 1));
  }
  cout << ans << endl;
  return 0;
}