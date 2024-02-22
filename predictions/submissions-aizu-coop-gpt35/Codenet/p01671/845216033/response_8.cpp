#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int64> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int find(int k) {
    if (data[k] < 0) return k;
    return data[k] = find(data[k]);
  }
  int size(int k) { return -data[find(k)]; }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1& e) const { return cost < e.cost; }
};

struct edge2 {
  int to, cost, idx;
};

struct CustomComparator {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first < b.first;
  }
};

int N, M, A[200000], B[200000], C[200000];
vector<edge1> edges;
bool killed[200000];
vector<edge2> tree[100000], g[100000];
int64 all, ans[200000];
set<pair<int, int>, CustomComparator> component[100000];

void rec(int idx, int par = -1) {
  for (const auto& e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (const auto& e : tree[idx]) {
    if (e.to == par) continue;
    rec(e.to, idx);
  }

  auto& u = component[idx];
  for (const auto& e : tree[idx]) {
    if (e.to == par) continue;
    auto& v = component[e.to];
    if (!v.empty()) {
      ans[e.idx] = all - e.cost + v.begin()->first;
    } else {
      ans[e.idx] = all;
    }
    u.insert(v.begin(), v.end());
  }
}

int main() {
  #pragma GCC optimize("Ofast")
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    edges.push_back((edge1){A[i], B[i], C[i], i});
  }
  UnionFind uf(N);
  sort(begin(edges), end(edges));
  for (const auto& e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++) {
      puts("-1");
    }
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
}