#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;

  QuickFind(int size) : r(size, 1), p(size), v(size) {
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
    if (r[x] < r[y])
      swap(x, y);
    r[x] += r[y];
    for (int i = 0; i < (int)v[y].size(); i++) {
      p[v[y][i]] = x;
      v[x].push_back(v[y][i]);
    }
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
  map<int, int> p;
  for (int i = 0; i < n; i++) {
    p[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[a[i]]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
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