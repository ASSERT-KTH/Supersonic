#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct UnionFind {
  int data[100000];
  UnionFind(int sz) {
    fill(data, data + sz, -1);
  }
  bool unite(int x, int y) {
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
  int size(int k) {
    return -data[find(k)];
  }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const {
    return cost < e.cost;
  }
};

struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
edge1 edges[200000];
bool killed[200000];
edge2 tree[100000][100000], g[100000][100000];
long long all, ans[200000];
pair<int, int> component[100000][100000];

void rec(int idx, int par = -1) {
  for (int i = 0; i < M; i++) {
    auto &e = g[idx][i];
    component[idx][i] = make_pair(e.cost, e.idx);
  }
  for (int i = 0; i < M; i++) {
    auto &e = tree[idx][i];
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (!v.empty()) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += v[0].first;
    }
    if (u.size() < v.size())
      swap(u, v);
    int j = 0;
    while (!v.empty()) {
      auto p = v[0];
      if (find(u.begin(), u.end(), p) != u.end())
        u.erase(find(u.begin(), u.end(), p));
      else
        u.push_back(p);
      pop_heap(v.begin(), v.end());
      v.pop_back();
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
  sort(edges, edges + M);
  for (int i = 0; i < M; i++) {
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
      tree[A[i]][i] = {B[i], C[i], i};
      tree[B[i]][i] = {A[i], C[i], i};
      ans[i] = -1;
    } else {
      g[A[i]][i] = {B[i], C[i], i};
      g[B[i]][i] = {A[i], C[i], i};
      ans[i] = all;
    }
  }
  rec(0);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
}