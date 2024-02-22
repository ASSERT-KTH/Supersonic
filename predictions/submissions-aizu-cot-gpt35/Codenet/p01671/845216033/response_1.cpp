#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int64> data;
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

  int64 find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int64 size(int k) { return (-data[find(k)]); }
};

struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
vector<pair<int, int>> edges;
bool killed[200000];
vector<priority_queue<pair<int, int>>> tree(100000), g(100000);
int64 all, ans[200000];

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
      ans[e.idx] += v.top().first;
    }
    if (u.size() < v.size())
      swap(u, v);
    while (!v.empty()) {
      auto p = v.top();
      if (u.count(p))
        u.erase(p);
      else
        u.emplace(p);
      v.pop();
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges.push_back(make_pair(C[i], i));
  }
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  for (auto &e : edges) {
    if (uf.unite(B[e.second], A[e.second])) {
      killed[e.second] = true;
      all += e.first;
    }
  }
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      puts("-1");
    return (0);
  }
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].emplace((edge2){B[i], C[i], i});
      tree[B[i]].emplace((edge2){A[i], C[i], i});
      ans[i] = -1;
    } else {
      g[A[i]].emplace((edge2){B[i], C[i], i});
      g[B[i]].emplace((edge2){A[i], C[i], i});
      ans[i] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
}