#include <bits/stdc++.h>
using namespace std;
#define int long long

struct QuickFind {
  vector<int> r, p, s, m;
  QuickFind() {}
  QuickFind(int size) { init(size); }
  void init(int size) {
    r = vector<int>(size, 1);
    p = vector<int>(size);
    s = vector<int>(size, 0);
    m = vector<int>(size, INT_MAX);
    iota(p.begin(), p.end(), 0);
  }
  bool same(int x, int y) { return p[x] == p[y]; }
  void unite(int x, int y, int val) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (r[x] < r[y])
      swap(x, y);
    r[x] += r[y];
    s[x] += s[y] + val;
    m[x] = min(m[x], min(m[y], val));
    p[y] = x;
  }
  int getMinSum(int minVal) {
    int sum = 0;
    for (int i = 0; i < p.size(); i++) {
      if (p[i] == i) {
        int k = r[i];
        sum += min(s[i] + m[i] * (k - 2), s[i] + m[i] + minVal * (k + 1));
      }
    }
    return sum;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  b = a;
  sort(b.begin(), b.end());
  
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }

  QuickFind qf(n);
  for (int i = 0; i < n; i++) {
    qf.s[p[b[i]]] = a[p[b[i]]];
    qf.m[p[b[i]]] = a[p[b[i]]];
    qf.unite(i, p[b[i]], a[p[b[i]]]);
  }

  cout << qf.getMinSum(b[0]) << endl;

  return 0;
}