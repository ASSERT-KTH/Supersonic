#include <bits/stdc++.h>
using namespace std;
#define int long long

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
  vector<int> parent(n), rank(n), min_val(n), sum(n);
  iota(parent.begin(), parent.end(), 0);
  fill(rank.begin(), rank.end(), 1);
  copy(a.begin(), a.end(), min_val.begin());
  copy(a.begin(), a.end(), sum.begin());

  auto find = [&](int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  };

  auto unite = [&](int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y])
      swap(x, y);
    parent[y] = x;
    rank[x] += rank[y];
    sum[x] += sum[y];
    min_val[x] = min(min_val[x], min_val[y]);
  };

  for (int i = 0; i < n; i++)
    unite(i, p[b[i]]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] != i)
      continue;
    int k = rank[i];
    int m = min_val[i];
    int s = sum[i];
    ans += min(s + m * (k - 2), s + m + b[0] * (k + 1));
  }
  cout << ans << endl;
  return 0;
}