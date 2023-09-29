#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using int64 = long long;
constexpr int MAX = 200000;

struct UnionFind {
  std::vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    if (data[x] > data[y])
      std::swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int find(int k) {
    return data[k] < 0 ? k : (data[k] = find(data[k]));
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

int N, M, A[MAX], B[MAX], C[MAX];
edge1 edges[MAX];
bool killed[MAX];
std::vector<edge2> tree[MAX], g[MAX];
int64 all, ans[MAX];
std::set<std::pair<int, int>> component[MAX];

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
      ans[e.idx] = all - e.cost + v.begin()->first;
    }
    if (u.size() < v.size())
      std::swap(u, v);
    for (auto it = v.begin(); it != v.end(); ) {
      auto p = *it;
      if (u.count(p))
        u.erase(p);
      else
        u.insert(p);
      it = v.erase(it);
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
  UnionFind uf(N);
  std::sort(edges, edges + M);
  for (int i = 0; i < M; ++i) {
    auto &e = edges[i];
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      puts("-1");
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
    printf("%lld\n", ans[i]);
  }
}