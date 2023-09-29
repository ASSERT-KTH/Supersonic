#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define int long long
struct QuickFind {
  std::vector<int> rank, parent;
  std::vector<std::vector<int>> group;
  
  QuickFind(int size) : rank(size, 1), parent(size), group(size, std::vector<int>(1)) {
    for (int i = 0; i < size; i++) {
      parent[i] = i;
      group[i][0] = i;
    }
  }
  
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (rank[x] < rank[y]) {
      std::swap(x, y);
    }
    rank[x] += rank[y];
    parent[y] = x;
    for (auto& i : group[y]) {
      parent[i] = x;
      group[x].push_back(i);
    }
    group[y].clear();
  }
};

signed main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  std::vector<int> b = a;
  std::sort(b.begin(), b.end());
  std::map<int, int> p, q;
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (qf.find(i) != i)
      continue;
    int m = a[qf.group[i][0]];
    int tmp = 0;
    for (auto& j : qf.group[i]) {
      tmp += a[j];
      m = std::min(m, a[j]);
    }
    ans += std::min(tmp + m * (qf.group[i].size() - 2), tmp + m + b[0] * (qf.group[i].size() + 1));
  }
  std::cout << ans << std::endl;
  return 0;
}