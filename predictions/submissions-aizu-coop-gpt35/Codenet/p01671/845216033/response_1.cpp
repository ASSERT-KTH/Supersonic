#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int find(int k) {
    if (data[k] < 0)
      return k;
    return data[k] = find(data[k]);
  }
  int size(int k) { return -data[find(k)]; }
};

struct Edge {
  int u, v, cost, idx;
};

int N, M;
int A[200000], B[200000], C[200000];
Edge edges[200000];
bool killed[200000];
vector<Edge> tree[100000], g[100000];
int64 all, ans[200000];
unordered_set<int> component[100000];

void rec(int idx) {
  stack<int> stk;
  stk.push(idx);
  
  while (!stk.empty()) {
    int curr = stk.top();
    stk.pop();
    
    for (auto& e : g[curr]) {
      component[curr].emplace(e.cost, e.idx);
    }
    
    for (auto& e : tree[curr]) {
      int to = e.to;
      
      if (to != -1) {
        stk.push(to);
        
        auto& u = component[curr];
        auto& v = component[to];
        
        if (!v.empty()) {
          ans[e.idx] = all;
          ans[e.idx] -= e.cost;
          ans[e.idx] += v.begin()->first;
        }
        
        if (u.size() < v.size()) {
          swap(u, v);
        }
        
        unordered_set<int> temp;
        
        for (auto p : v) {
          if (u.count(p)) {
            u.erase(p);
          } else {
            temp.insert(p);
          }
        }
        
        for (auto p : temp) {
          u.emplace(p);
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges[i] = {A[i], B[i], C[i], i};
  }

  UnionFind uf(N);
  
  // Radix Sort
  for (int i = 0; i < M; i++) {
    int digit = edges[i].cost;
    for (int j = 0; j < 4; j++) {
      int bucket = digit % 256;
      digit /= 256;
      
      edges[i] = {A[i], B[i], C[i], i};
      
      edges[i] = {A[i], B[i], C[i], i};
      buckets[bucket].emplace_back(edges[i]);
    }
  }
  
  int pos = 0;
  
  for (int i = 0; i < 256; i++) {
    for (auto& edge : buckets[i]) {
      A[pos] = edge.u;
      B[pos] = edge.v;
      C[pos] = edge.cost;
      edges[pos] = edge;
      pos++;
    }
  }
  
  for (int i = 0; i < M; i++) {
    if (uf.unite(edges[i].v, edges[i].u)) {
      killed[edges[i].idx] = true;
      all += edges[i].cost;
    }
  }
  
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++) {
      puts("-1");
    }
    return 0;
  }
  
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].emplace_back(Edge{B[i], C[i], i});
      tree[B[i]].emplace_back(Edge{A[i], C[i], i});
      ans[i] = -1;
    } else {
      g[A[i]].emplace_back(Edge{B[i], C[i], i});
      g[B[i]].emplace_back(Edge{A[i], C[i], i});
      ans[i] = all;
    }
  }
  
  rec(0);
  
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
  
  return 0;
}