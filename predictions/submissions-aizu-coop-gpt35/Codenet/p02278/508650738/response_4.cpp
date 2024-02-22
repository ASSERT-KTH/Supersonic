#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

struct QuickFind {
  vector<int> r, p, v_size, v_min, v_sum;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v_size.resize(size, 0);
    v_min.resize(size, 0);
    v_sum.resize(size, 0);
    for (int i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v_size[i] = 1;
      v_min[i] = i;
      v_sum[i] = i;
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
    v_size[x] += v_size[y];
    v_min[x] = min(v_min[x], v_min[y]);
    v_sum[x] += v_sum[y];
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

  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    p[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    q[b[i]] = i;
  }

  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[i]);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int root = qf.p[i];
    if (root != i || qf.v_size[root] == 1)
      continue;
    int k = qf.v_size[root];
    int m = qf.v_min[root];
    int tmp = qf.v_sum[root];
    ans += min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }

  cout << ans << endl;
  return 0;
}