#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
  int size(int k) { return (-data[find(k)]); }
};

struct Edge {
  int from, to, cost, idx;
  bool operator<(const Edge &e) const { return (cost < e.cost); }
};

int N, M;
vector<Edge> edges;
bool killed[200000];
vector<Edge> tree[100000], g[100000];
int64 all, ans[200000];
vector<pair<int, int>> component[100000];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].push_back(make_pair(e.cost, e.idx));
  }
  sort(component[idx].begin(), component[idx].end());
  for (auto &e : tree[idx]) {
    if (e.to == par) continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (u.size() < v.size()) swap(u, v);
    while (!v.empty()) {
      auto p = v.begin();
      auto it = find(u.begin(), u.end(), *p);
      if (it != u.end()) u.erase(it);
      else u.push_back(*p);
      v.erase(p);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  edges.resize(M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
    --edges[i].from, --edges[i].to;
    edges[i].idx = i;
  }
  UnionFind uf(N);
  sort(edges.begin(), edges.end());
  for (auto &e : edges) {
    if (uf.unite(e.to, e.from)) {
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
      tree[edges[i].from].push_back(edges[i]);
      tree[edges[i].to].push_back(edges[i]);
      ans[i] = -1;
    } else {
      g[edges[i].from].push_back(edges[i]);
      g[edges[i].to].push_back(edges[i]);
      ans[i] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
}