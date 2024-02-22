#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
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
void rec(int idx, int par, vector<edge2> (&tree)[100000], vector<edge2> (&g)[100000], set<pair<int, int>> (&component)[100000], ll (&ans)[200000], ll &all) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx, tree, g, component, ans, all);
    auto &u = component[idx], &v = component[e.to];
    if (u.size() < v.size())
      swap(u, v);
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
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  scanf("%d %d", &N, &M);
  vector<edge1> edges(M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
    --edges[i].u, --edges[i].v;
    edges[i].idx = i;
  }
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  vector<bool> killed(M, false);
  ll all = 0;
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
  vector<edge2> tree[100000], g[100000];
  ll ans[200000];
  set<pair<int, int>> component[100000];
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[edges[i].u].emplace_back((edge2){edges[i].v, edges[i].cost, i});
      tree[edges[i].v].emplace_back((edge2){edges[i].u, edges[i].cost, i});
      ans[i] = -1;
    } else {
      g[edges[i].u].emplace_back((edge2){edges[i].v, edges[i].cost, i});
      g[edges[i].v].emplace_back((edge2){edges[i].u, edges[i].cost, i});
      ans[i] = all;
    }
  }
  rec(0, -1, tree, g, component, ans, all);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}