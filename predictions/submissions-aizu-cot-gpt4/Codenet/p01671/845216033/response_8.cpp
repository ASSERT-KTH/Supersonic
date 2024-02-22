#include <iostream>
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
    if (x != y) {
      if (data[x] > data[y])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
      return true;
    }
    return false;
  }
  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }
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
vector<vector<edge2>> tree;
vector<vector<edge2>> g;
int64 all, ans[200000];
vector<set<pair<int, int>>> component;

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    if (!component[e.to].empty()) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += component[e.to].begin()->first;
    }
    if (component[idx].size() < component[e.to].size())
      swap(component[idx], component[e.to]);
    while (!component[e.to].empty()) {
      auto p = component[e.to].begin();
      if (component[idx].count(*p))
        component[idx].erase(*p);
      else
        component[idx].emplace(*p);
      component[e.to].erase(p);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  edges.resize(M);
  tree.resize(N);
  g.resize(N);
  component.resize(N);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    edges[i] = {A[i], B[i], C[i], i};
  }
  UnionFind uf(N);
  sort(edges.begin(), edges.end());
  for (auto &e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  if (uf.find(0) != N) {
    for (int i = 0; i < M; i++)
      cout << "-1\n";
    return 0;
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
    cout << ans[i] << "\n";
  }
}