#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
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
      swap(x, y);
    r[x] += r[y];
    for (int i : v[y]) {
      p[i] = x;
    }
    v[x].insert(v[x].end(), make_move_iterator(v[y].begin()), make_move_iterator(v[y].end()));
    v[y].clear();
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  unordered_map<int, int> p, q;
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
      continue;
    long long m = a[qf.v[i][0]];
    long long tmp = 0;
    for (int j : qf.v[i]) {
      tmp += a[j];
      m = min(m, (long long)a[j]);
    }
    long long m1 = m + b[0] * (k + 1);
    ans += min(tmp + m * (k - 2), m1);
  }
  cout << ans << endl;
  return 0;
}