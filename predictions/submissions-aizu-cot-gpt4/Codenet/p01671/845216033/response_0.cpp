#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  int data[200005];
  UnionFind(int sz) {
    for(int i=0; i<sz; i++)
      data[i]=-1;
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }
  int size(int k) { return (-data[find(k)]); }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const { return (cost < e.cost); }
};
struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
edge1 edges[200005];
bool killed[200000];
edge2 tree[100000][100000], g[100000][100000];
int64 all, ans[200000];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].insert(e.cost);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (!v.empty()) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += *v.begin();
    }
    if (u.size() < v.size())
      swap(u, v);
    while (!v.empty()) {
      auto p = *v.begin();
      if (u.count(p))
        u.erase(p);
      else
        u.insert(p);
      v.erase(p);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges[i]={A[i], B[i], C[i], i};
  }
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  for (auto &e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      puts("-1");
    return (0);
  }
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].push_back({B[i], C[i], i});
      tree[B[i]].push_back({A[i], C[i], i});
      ans[i] = -1;
    } else {
      g[A[i]].push_back({B[i], C[i], i});
      g[B[i]].push_back({A[i], C[i], i});
      ans[i] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
}