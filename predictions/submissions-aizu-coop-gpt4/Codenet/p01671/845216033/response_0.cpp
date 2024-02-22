#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct UnionFind {
  vector<int> data;
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

struct edge {
  int u, v, cost, idx;
  bool operator<(const edge &e) const { return cost < e.cost; }
};

int N, M, A[200000], B[200000], C[200000];
vector<edge> edges;
bool killed[200000];
vector<edge> tree[100000], g[100000];
int64 all, ans[200000];

// Use priority_queue instead of set
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> component[100000];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].push({e.cost, e.idx});
  }
  for (auto &e : tree[idx]) {
    if (e.to == par) continue;
    rec(e.to, idx);
    if (!component[e.to].empty()) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += component[e.to].top().first;
    }
    while (!component[e.to].empty()) {
      component[idx].push(component[e.to].top());
      component[e.to].pop();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // fast I/O
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    edges.push_back({A[i], B[i], C[i], i});
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