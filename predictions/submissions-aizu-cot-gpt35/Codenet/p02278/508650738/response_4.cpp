#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct QuickFind {
  vector<int> p;
  vector<vector<int>> v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    p.resize(size, 0);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      p[i] = i;
      v[i].push_back(i);
    }
  }
  bool same(int x, int y) { return p[x] == p[y]; }
  void unite(int x, int y) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (v[x].size() < v[y].size())
      swap(x, y);
    p[y] = x;
    v[x].insert(v[x].end(), v[y].begin(), v[y].end());
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
  map<int, int> p, q;
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);
  int ans = 0;
  int m = a[qf.v[0][0]];
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
      continue;
    tmp += k * a[qf.v[i][0]];
    m = min(m, a[qf.v[i][0]]);
  }
  ans = min(tmp + m * (n - 2), tmp + m + b[0] * n);
  cout << ans << endl;
  return 0;
}