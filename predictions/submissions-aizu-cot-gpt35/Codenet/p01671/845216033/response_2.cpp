#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

const int MAX_N = 100000;
const int MAX_M = 200000;

int N, M, A[MAX_M], B[MAX_M], C[MAX_M];
vector<edge1> edges;
bool killed[MAX_M];
vector<edge2> tree[MAX_N], g[MAX_N];
int64 all, ans[MAX_M];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> component[MAX_N];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx].emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
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
      v.pop();
      if (!u.empty() && u.top() == p)
        u.pop();
      else
        u.push(p);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    edges.push_back({A[i], B[i], C[i], i});
  }
  
  UnionFind uf(N);
  sort(edges.begin(), edges.end());
  
  for (auto &e : edges) {
    if (uf.unite(e.v, e.u)) {
      killed[e.idx] = true;
      all += e.cost;
    }
  }
  
  if (uf.size(0) != N) {
    for (int i = 0; i < M; i++)
      cout << -1 << "\n";
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
  
  return 0;
}