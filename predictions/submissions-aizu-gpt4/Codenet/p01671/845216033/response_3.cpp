#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
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
    return (data[k] < 0 ? k : data[k] = find(data[k]));
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
vector<edge1> edges;
bool killed[200000];
vector<edge2> tree[100000], g[100000];
int64 all, ans[200000];
set<pair<int, int>> component[100000];
void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (u.size() < v.size())
      swap(u, v);
    while (!v.empty()) {
      auto p = *v.begin();
      u.erase(p);
      v.erase(v.begin());
    }
  }
  if (!component[idx].empty()) {
    auto p = *component[idx].begin();
    ans[p.second] = all - p.first;
  }
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges.push_back((edge1){A[i], B[i], C[i], i});
  }
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  for (auto &e : edges) {
    if (uf.unite(e.u, e.v)) {
      all += e.cost;
      killed[e.idx] = true;
    }
  }
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      puts("-1");
    return (0);
  }
  for (auto &e : edges) {
    if (killed[e.idx]) {
      tree[e.u].emplace_back((edge2){e.v, e.cost, e.idx});
      tree[e.v].emplace_back((edge2){e.u, e.cost, e.idx});
      ans[e.idx] = -1;
    } else {
      g[e.u].emplace_back((edge2){e.v, e.cost, e.idx});
      g[e.v].emplace_back((edge2){e.u, e.cost, e.idx});
      ans[e.idx] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
}