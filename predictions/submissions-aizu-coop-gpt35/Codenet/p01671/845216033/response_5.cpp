#include <iostream>
#include <vector>
#include <algorithm>

using int64 = long long;

struct UnionFind {
  std::vector<int64> data;

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
    if (data[k] < 0)
      return k;
    return (data[k] = find(data[k]));
  }

  int size(int k) { return (-data[find(k)]); }
};

struct edge {
  int u, v, cost;
  bool operator<(const edge &e) const { return cost < e.cost; }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int N, M;
  std::cin >> N >> M;

  std::vector<int> A(M), B(M), C(M);
  std::vector<edge> edges(M);

  for (int i = 0; i < M; i++) {
    std::cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    edges[i] = {A[i], B[i], C[i]};
  }

  UnionFind uf(N);
  std::sort(edges.begin(), edges.end());

  int64 all = 0;
  std::vector<bool> killed(M, false);
  for (auto &e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }

  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      std::cout << "-1\n";
    return 0;
  }

  std::vector<std::vector<int>> tree(N), g(N);
  std::vector<int64> ans(M, 0);

  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].push_back(B[i]);
      tree[B[i]].push_back(A[i]);
      ans[i] = -1;
    } else {
      g[A[i]].push_back(B[i]);
      g[B[i]].push_back(A[i]);
      ans[i] = all;
    }
  }

  std::vector<int64> min_cost(N, INT_MAX);
  std::vector<int> parent(N, -1);
  std::vector<int> stack;

  stack.push_back(0);
  while (!stack.empty()) {
    int node = stack.back();
    stack.pop_back();

    for (auto &child : g[node]) {
      if (child == parent[node])
        continue;
      parent[child] = node;
      stack.push_back(child);
    }

    for (auto &child : tree[node]) {
      if (child == parent[node])
        continue;
      parent[child] = node;
      stack.push_back(child);
      ans[child] = ans[node] + min_cost[node] - min_cost[child];
      min_cost[child] = std::min(min_cost[child], min_cost[node]);
    }
  }

  for (int i = 0; i < M; i++) {
    std::cout << ans[i] << "\n";
  }

  return 0;
}