#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct QuickFind {
  std::vector<int> r, p;
  std::vector<std::vector<int>> v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; ++i) {
      r[i] = 1, p[i] = i;
      v[i].resize(1, i);
    }
  }
  bool same(int x, int y) { return p[x] == p[y]; }
  void unite(int x, int y) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (r[x] < r[y])
      std::swap(x, y);
    r[x] += r[y];
    v[x].reserve(v[x].size() + v[y].size());
    for (int i = 0; i < static_cast<int>(v[y].size()); ++i) {
      p[v[y][i]] = x;
      v[x].emplace_back(v[y][i]);
    }
    v[y].clear();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  std::vector<int> b(a);
  std::sort(b.begin(), b.end());
  std::map<int, int> p, q;
  for (int i = 0; i < n; ++i) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; ++i)
    qf.unite(i, p[b[i]]);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
      continue;
    int m = a[qf.v[i][0]];
    int tmp = 0;
    for (int j = 0; j < k; ++j) {
      tmp += a[qf.v[i][j]];
      m = std::min(m, a[qf.v[i][j]]);
    }
    ans += std::min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }
  std::cout << ans << std::endl;
  return 0;
}