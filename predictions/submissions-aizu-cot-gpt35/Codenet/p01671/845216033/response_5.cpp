#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
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
  int size(int k) { return -data[find(k)]; }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const { return cost < e.cost; }
};

struct edge2 {
  int to, cost, idx;
};

int N, M;
vector<int> A, B, C;
vector<edge1> edges;
vector<bool> killed;
vector<edge2> tree[100000], g[100000];
int64 all;
vector<int64> ans;

unordered_set<pair<int, int>> component[100000];

void rec(int idx, int par = -1) {
  auto& u = component[idx];
  for (auto &e : g[idx]) {
    u.emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto& v = component[e.to];
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
  
  A.reserve(M);
  B.reserve(M);
  C.reserve(M);
  killed.resize(M);
  edges.reserve(M);
  ans.resize(M);

  for (int i = 0; i < M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a, --b;
    A.emplace_back(a);
    B.emplace_back(b);
    C.emplace_back(c);
    edges.emplace_back((edge1){a, b, c, i});
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
    return 0;
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