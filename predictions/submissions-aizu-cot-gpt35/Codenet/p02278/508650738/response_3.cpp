#include <iostream>
#include <vector>
#include <algorithm>

struct QuickFind {
  std::vector<int> r, p, v;
  
  QuickFind() {}
  QuickFind(int size) { init(size); }
  
  void init(int size) {
    r.resize(size, 0);
    p.resize(size, 0);
    v.resize(size);
    
    for (int i = 0; i < size; i++) {
      r[i] = 1;
      p[i] = i;
      v[i] = i;
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
    
    for (int i = 0; i < v.size(); i++) {
      if (p[v[i]] == y)
        p[v[i]] = x;
    }
    
    v[y] = x;
  }
};

int main() {
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  
  std::vector<int> b(a);
  std::sort(b.begin(), b.end());
  
  std::vector<int> p(n), q(n);
  
  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }
  
  QuickFind qf(n);
  
  for (int i = 0; i < n; i++)
    qf.unite(i, p[b[i]]);
  
  int ans = 0;
  
  for (int i = 0; i < n; i++) {
    int k = 0;
    int parent = qf.v[i];
    
    while (parent != i) {
      k++;
      parent = qf.v[parent];
    }
    
    if (qf.p[i] != i || k == 0)
      continue;
    
    int m = a[qf.v[i]];
    int tmp = a[qf.v[i]];
    
    for (int j = 1; j < k; j++) {
      tmp += a[qf.v[i]];
      m = std::min(m, a[qf.v[i]]);
    }
    
    if (k == 1)
      ans += tmp + m * (k - 2);
    else
      ans += std::min(tmp + m * (k - 2), tmp + m + b[0] * (k + 1));
  }
  
  std::cout << ans << std::endl;
  return 0;
}