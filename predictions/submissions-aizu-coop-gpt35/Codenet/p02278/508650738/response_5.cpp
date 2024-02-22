#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;

  QuickFind() {}
  QuickFind(size_t size) { init(size); }

  void init(size_t size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    for (size_t i = 0; i < size; i++) {
      r[i] = 1;
      p[i] = i;
      v[i].emplace_back(i);
    }
  }

  bool same(size_t x, size_t y) { return p[x] == p[y]; }

  void unite(size_t x, size_t y) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (r[x] < r[y]) {
      r[x] += r[y];
      for (auto it = v[y].begin(); it != v[y].end(); ++it) {
        p[*it] = x;
        v[x].emplace_back(*it);
      }
      v[y].clear();
    } else {
      r[y] += r[x];
      for (auto it = v[x].begin(); it != v[x].end(); ++it) {
        p[*it] = y;
        v[y].emplace_back(*it);
      }
      v[x].clear();
    }
  }
};

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  map<int, size_t> p, q;
  for (size_t i = 0; i < n; i++) {
    p.emplace(a[i], i);
    q.emplace_hint(q.end(), a[i], i);
  }
  QuickFind qf(n);
  for (size_t i = 0; i < n; i++)
    qf.unite(i, p[a[i]]);
  int ans = 0;
  for (size_t i = 0; i < n; i++) {
    auto& vi = qf.v[i];
    size_t k = vi.size();
    if (qf.p[i] != i || k == 1)
      continue;
    int m = a[vi[0]];
    int tmp = 0;
    for (auto it = vi.begin(); it != vi.end(); ++it) {
      tmp += a[*it];
      m = min(m, a[*it]);
    }
    ans += min(tmp + m * (k - 2), tmp + m + a[0] * (k + 1));
  }
  cout << ans << endl;
  return 0;
}