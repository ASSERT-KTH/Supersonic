#include <iostream>
#include <vector>
#include <numeric>

struct SegmentTree {
  std::vector<int> seg, add;
  int sz;
  
  SegmentTree(int n) : sz(1) {
    while (sz < n)
      sz *= 2;
    seg.resize(sz * 2 + 1, 0);
    add.resize(sz * 2 + 1, 0);
  }
  
  void Add(int a, int b, int x) {
    int k = 0, l = 0, r = sz;
    std::vector<int> nodes;
    
    while (true) {
      seg[k] += x;
      
      if (a <= l && r <= b) {
        add[k] += x;
        break;
      }
      
      int m = (l + r) / 2;
      
      if (a < m) {
        nodes.push_back(2 * k + 1);
        r = m;
        k = 2 * k + 1;
      } else {
        nodes.push_back(2 * k + 2);
        l = m;
        k = 2 * k + 2;
      }
    }
    
    for (int i = nodes.size() - 2; i >= 0; i--) {
      int node = nodes[i];
      seg[node] = seg[2 * node + 1] + add[2 * node + 1] + seg[2 * node + 2] + add[2 * node + 2];
    }
  }
  
  int Query(int a, int b) {
    int k = 0, l = 0, r = sz;
    int res = 0;
    std::vector<int> nodes;
    
    while (true) {
      if (a <= l && r <= b)
        return res + seg[k] + add[k];
      
      res += add[k];
      
      int m = (l + r) / 2;
      
      if (a < m) {
        nodes.push_back(2 * k + 1);
        r = m;
        k = 2 * k + 1;
      } else {
        nodes.push_back(2 * k + 2);
        l = m;
        k = 2 * k + 2;
      }
    }
    
    for (int i = nodes.size() - 2; i >= 0; i--) {
      int node = nodes[i];
      res += add[node];
    }
    
    return res;
  }
};

int main() {
  int N, M;
  std::cin >> N >> M;
  
  SegmentTree segtree(N);
  
  std::vector<int> P(M);
  for (int i = 0; i < M; i++) {
    std::cin >> P[i];
    --P[i];
  }
  
  for (int i = 0; i < M - 1; i++) {
    int u = std::min(P[i], P[i + 1]);
    int v = std::max(P[i], P[i + 1]);
    segtree.Add(u, v, 1);
  }
  
  long long ret = 0;
  
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    std::cin >> A >> B >> C;
    ret += std::min(used * A, C + used * B);
  }
  
  std::cout << ret << std::endl;
  return 0;
}