#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAXN = 100005;
const int MAXM = 200005;
int N, M, A[MAXM], B[MAXM], C[MAXM], par[MAXN], rnk[MAXN], sz[MAXN];
int64 all, ans[MAXM];
set<pair<int, int>> component[MAXN];
void makeSet(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
    sz[i] = 1;
  }
}
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  all += (int64)sz[x] * sz[y] * 2;
  if (rnk[x] == rnk[y]) ++rnk[x];
}
struct Edge {
  int u, v, cost, idx;
  bool operator<(const Edge &e) const { return (cost < e.cost); }
} edges[MAXM];
struct Edge2 {
  int to, cost, idx;
};
vector<Edge2> tree[MAXN], g[MAXN];
void rec(int idx, int p = -1) {
  for (auto &e : g[idx]) component[idx].emplace(e.cost, e.idx);
  for (auto &e : tree[idx]) {
    if (e.to == p) continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (!v.empty()) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += v.begin()->first;
    }
    if (u.size() < v.size()) swap(u, v);
    while (!v.empty()) {
      auto p = v.begin();
      if (u.count(*p))
        u.erase(*p);
      else
        u.emplace(*p);
      v.erase(p);
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
  sort(edges, edges + M);
  makeSet(N);
  for (int i = 0; i < M; i++) {
    int u = edges[i].u, v = edges[i].v, cost = edges[i].cost, idx = edges[i].idx;
    if (find(u) == find(v)) continue;
    unite(u, v);
    tree[u].push_back({v, cost, idx});
    tree[v].push_back({u, cost, idx});
  }
  if (sz[find(0)] != N) {
    for (int i = 0; i < M; i++) puts("-1");
    return 0;
  }
  makeSet(N);
  for (int i = 0; i < M; i++) {
    int u = edges[i].u, v = edges[i].v, cost = edges[i].cost, idx = edges[i].idx;
    if (find(u) == find(v)) continue;
    unite(u, v);
    g[u].push_back({v, cost, idx});
    g[v].push_back({u, cost, idx});
    ans[idx] = all;
  }
  rec(0);
  for (int i = 0; i < M; i++) printf("%lld\n", ans[i]);
}
