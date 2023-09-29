#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

const int MAX_M = 200000;
const int MAX_N = 100000;

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

int N, M, A[MAX_M], B[MAX_M], C[MAX_M];
vector<edge1> edges;
bool killed[MAX_M];
vector<edge2> tree[MAX_N], g[MAX_N];
int64 all, ans[MAX_M];
set<pair<int, int>> component[MAX_N];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
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
      puts("-1");
    return (0);
  }
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].emplace_back((edge2){B[i], C[i], i});
      tree[B[i]].emplace_back((edge2){A[i], C[i], i});
      ans[i] = -1;
    } else {
      g[A[i]].emplace_back((edge2){B[i], C[i], i});
      g[B[i]].emplace_back((edge2){A[i], C[i], i});
      ans[i] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}