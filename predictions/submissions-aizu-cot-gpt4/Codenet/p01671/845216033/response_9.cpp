#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
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
vector<edge1> edges;
bool killed[200000];
vector<vector<edge2>> tree, g;
int64 all, ans[200000];
vector<set<pair<int, int>>> component;
void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].insert({e.cost, e.idx});
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    if (!component[e.to].empty()) {
      ans[e.idx] = all - e.cost + component[e.to].begin()->first;
    }
    if (component[idx].size() < component[e.to].size()) {
      swap(component[idx], component[e.to]);
    }
    auto it = component[e.to].begin();
    while (it != component[e.to].end()) {
      auto p = *it;
      if (component[idx].count(p)) {
        component[idx].erase(p);
      } else {
        component[idx].insert(p);
      }
      component[e.to].erase(it++);
    }
  }
}
int main() {
  scanf("%d %d", &N, &M);
  tree.resize(N);
  g.resize(N);
  component.resize(N);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges.push_back({A[i], B[i], C[i], i});
  }
  UnionFind uf(N);
  sort(edges.begin(), edges.end());
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