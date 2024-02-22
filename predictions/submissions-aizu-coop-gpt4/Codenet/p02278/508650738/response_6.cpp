#include <bits/stdc++.h>
using namespace std;
#define int long long

struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i].resize(1, i);
    }
  }
  int find(int x) {
    if (p[x] != x) {
      p[x] = find(p[x]); // path compression
    }
    return p[x];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (r[x] < r[y])
      swap(x, y);
    r[x] += r[y];
    p[y] = x; // union by rank
    v[x].insert(v[x].end(), v[y].begin(), v[y].end());
    v[y].clear();
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  map<int, int> q;
  for (int i = 0; i < n; i++) 
    q[b[i]] = i;
  
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, q[a[i]]);
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (qf.p[i] != i)
      continue;
    int k = qf.v[i].size();
    if (k == 1)
      continue;
    int m = a[qf.v[i][0]];
    int tmp = 0;
    for (int j = 0; j < k; j++) {
      tmp += a[qf.v[i][j]];
      m = min(m, a[qf.v[i][j]]);
    }
    ans += min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }
  cout << ans << endl;
  return 0;
}