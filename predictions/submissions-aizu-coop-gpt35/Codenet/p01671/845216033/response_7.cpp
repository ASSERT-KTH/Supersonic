#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  
  int find(int k) {
    if (data[k] < 0)
      return k;
    return data[k] = find(data[k]); // Path compression optimization
  }
  
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
  
  int size(int k) { return -data[find(k)]; }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1& e) const { return cost < e.cost; }
};

struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
vector<edge1> edges;
bool killed[200000];
vector<vector<edge2>> adjList;
int64 all, ans[200000];
set<pair<int, int>> component[100000];

int rec(int idx) {
  int componentSize = 1;
  
  for (auto& e : adjList[idx]) {
    component[idx].insert({e.cost, e.idx});
  }
  
  for (auto& e : adjList[idx]) {
    int childSize = rec(e.to);
    componentSize += childSize;
    
    auto& u = component[idx];
    auto& v = component[e.to];
    
    if (!v.empty()) {
      ans[e.idx] = all - e.cost + v.begin()->first;
    }
    
    if (u.size() < v.size())
      swap(u, v);
    
    while (!v.empty()) {
      auto p = v.begin();
      if (u.count(*p))
        u.erase(*p);
      else
        u.insert(*p);
      v.erase(p);
    }
  }
  
  return componentSize;
}

int main() {
  scanf("%d %d", &N, &M);
  
  adjList.resize(N);
  
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges.push_back({A[i], B[i], C[i], i});
    adjList[A[i]].push_back({B[i], C[i], i});
    adjList[B[i]].push_back({A[i], C[i], i});
  }
  
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  
  for (auto& e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      puts("-1");
    return 0;
  }
  
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      ans[i] = -1;
    } else {
      ans[i] = all;
    }
  }
  
  rec(0);
  
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
  
  return 0;
}