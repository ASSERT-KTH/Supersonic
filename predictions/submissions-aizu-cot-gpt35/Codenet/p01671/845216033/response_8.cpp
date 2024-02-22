#include <iostream>
#include <vector>
#include <set>
using namespace std;

using int64 = long long;

struct edge1;
struct edge2;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unite(int& x, int& y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int find(int k) {
    if (data[k] < 0)
      return k;
    return data[k] = find(data[k]);
  }
  int size(int k) { return -data[find(k)]; }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const { return cost < e.cost; }
};

struct edge2 {
  int to, cost, idx;
};

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  vector<int> A(M), B(M), C(M);
  vector<edge1> edges(M);
  vector<bool> killed(M);

  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges[i] = {A[i], B[i], C[i], i};
  }

  UnionFind uf(N);
  sort(begin(edges), end(edges));

  int64 all = 0;
  for (const auto &e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }

  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      printf("-1\n");
    return 0;
  }

  vector<vector<edge2>> tree(N), g(N);
  vector<set<pair<int, int>>> component(N);
  vector<int64> ans(M);

  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].emplace_back(edge2{B[i], C[i], i});
      tree[B[i]].emplace_back(edge2{A[i], C[i], i});
      ans[i] = -1;
    } else {
      g[A[i]].emplace_back(edge2{B[i], C[i], i});
      g[B[i]].emplace_back(edge2{A[i], C[i], i});
      ans[i] = all;
    }
  }

  auto rec = [&](int idx, int par = -1) {
    for (const auto &e : g[idx]) {
      component[idx].emplace(e.cost, e.idx);
    }

    for (const auto &e : tree[idx]) {
      if (e.to == par)
        continue;

      rec(e.to, idx);
      auto &u = component[idx], &v = component[e.to];

      if (!v.empty()) {
        ans[e.idx] = all;
        ans[e.idx] -= e.cost;
        ans[e.idx] += v.begin()->first;
      }

      if (u.size() < v.size())
        swap(u, v);

      while (!v.empty()) {
        auto it = v.begin();
        u.erase(*it);
        v.erase(it);
      }
    }
  };

  rec(0);

  for (const auto &res : ans) {
    printf("%lld\n", res);
  }

  return 0;
}