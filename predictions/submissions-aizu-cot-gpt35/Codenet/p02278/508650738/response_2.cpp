#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct QuickFind {
  vector<int64_t> r, p;
  vector<vector<int64_t>> v;

  QuickFind() {}

  QuickFind(int64_t size) {
    init(size);
  }

  void init(int64_t size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);

    for (int64_t i = 0; i < size; i++) {
      r[i] = 1, p[i] = i;
      v[i].push_back(i);
    }
  }

  bool same(int64_t x, int64_t y) {
    return p[x] == p[y];
  }

  void unite(int64_t x, int64_t y) {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    if (r[x] < r[y])
      swap(x, y);

    r[x] += r[y];

    for (int64_t i = 0; i < (int64_t)v[y].size(); i++) {
      p[v[y][i]] = x;
      v[x].push_back(v[y][i]);
    }

    v[y].clear();
  }

  int64_t find(int64_t x) {
    if (p[x] != x)
      p[x] = find(p[x]);

    return p[x];
  }
};

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++)
    cin >> a[i];

  vector<int64_t> b(a);
  nth_element(b.begin(), b.begin() + n, b.end());

  vector<int64_t> p(n), q(n);
  for (int64_t i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }

  QuickFind qf(n);
  for (int64_t i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);

  int64_t ans = 0;

  for (int64_t i = 0; i < n; i++) {
    int64_t k = qf.v[i].size();
    if (qf.find(i) != i || k == 1)
      continue;

    int64_t m = a[qf.v[i][0]];
    int64_t tmp = 0;

    for (int64_t j = 0; j < k; j++) {
      tmp += a[qf.v[i][j]];
      m = min(m, a[qf.v[i][j]]);
    }

    ans += min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }

  cout << ans << endl;

  return 0;
}