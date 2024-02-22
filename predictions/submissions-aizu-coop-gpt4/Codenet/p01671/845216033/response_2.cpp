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
vector<int64> ans;
vector<vector<Edge>> tree, g;
vector<set<pair<int, int>>> component;
bool killed[200000];
int64 all = 0;

void rec(int idx, int par = -1) {
  for (auto &e : g[idx])
    component[idx].emplace(e.cost, e.idx);

  for (auto &e : tree[idx]) {
    if (e.to == par) continue;
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
      if (u.count(*p)) u.erase(*p);
      else u.emplace(*p);
      v.erase(p);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); // Fast IO
  cin.tie(NULL); // Untie cin and cout

  cin >> N >> M;

  edges.reserve(M); // Preallocate memory
  ans.resize(M, -1);
  tree.resize(N);
  g.resize(N);
  component.resize(N);

  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    edges.push_back({a, b, c, i});
  }

  UnionFind uf(N);
  sort(begin(edges), end(edges));

  for (auto &e : edges) {
    if (uf.unite(e.to, e.from)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }

  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      cout << "-1\n";
    return (0);
  }

  for (auto &e : edges) {
    if (killed[e.idx]) {
      tree[e.from].push_back(e);
      tree[e.to].push_back({e.to, e.from, e.cost, e.idx});
    } else {
      g[e.from].push_back(e);
      g[e.to].push_back({e.to, e.from, e.cost, e.idx});
      ans[e.idx] = all;
    }
  }

  rec(0);

  for (auto &a : ans)
    cout << a << "\n";

  return 0;
}