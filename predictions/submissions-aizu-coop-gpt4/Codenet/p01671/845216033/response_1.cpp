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

void rec(int idx, vector<int64>& ans, vector<unordered_set<pair<int, int>>>& component, vector<vector<edge2>>& tree, vector<vector<edge2>>& g, int64 all, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, ans, component, tree, g, all, idx);
    auto &u = component[idx], &v = component[e.to];
    if (!v.empty()) {
      int64 ans_tmp = all - e.cost + v.begin()->first;
      ans[e.idx] = ans_tmp;
    }
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
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M), C(M);
  vector<edge1> edges;
  vector<bool> killed(M, false);
  vector<unordered_set<pair<int, int>>> component(N);
  vector<vector<edge2>> tree(N), g(N);
  vector<int64> ans(M, -1);
  int64 all = 0;

  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    edges.push_back((edge1){A[i], B[i], C[i], i});
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
      cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].push_back((edge2){B[i], C[i], i});
      tree[B[i]].push_back((edge2){A[i], C[i], i});
    } else {
      g[A[i]].push_back((edge2){B[i], C[i], i});
      g[B[i]].push_back((edge2){A[i], C[i], i});
      ans[i] = all;
    }
  }

  rec(0, ans, component, tree, g, all);
  for (int i = 0; i < M; i++) {
    cout << ans[i] << '\n';
  }
}