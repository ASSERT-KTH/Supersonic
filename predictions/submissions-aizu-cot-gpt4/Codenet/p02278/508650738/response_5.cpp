#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define int long long
#define SIZE 1
#define INITIAL_PARENT 0

struct QuickFind {
  vector<int> r, p;
  vector<vector<int>> v;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r.resize(size, SIZE);
    p.resize(size, INITIAL_PARENT);
    v.resize(size);
    for (int i = 0; i < size; i++) {
      r[i] = SIZE, p[i] = i;
      v[i].resize(SIZE, i);
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
    p[v[y].front()] = x;
    v[x].insert(v[x].end(), make_move_iterator(v[y].begin()), make_move_iterator(v[y].end()));
    v[y].clear();
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
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == SIZE)
      continue;
    int m = a[qf.v[i][INITIAL_PARENT]];
    int tmp = 0;
    for (int j = 0; j < k; j++) {
      tmp += a[qf.v[i][j]];
      m = min(m, a[qf.v[i][j]]);
    }
    ans += min(tmp + m * (k - 2), tmp + m + b[INITIAL_PARENT] * (k + 1));
  }
  cout << ans << endl;
  return 0;
}