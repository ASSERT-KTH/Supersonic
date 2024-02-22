#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct UnionFind {
  vector<int> data;
  vector<int> component_size; // Added to store component sizes

  UnionFind(int sz) : data(sz, -1), component_size(sz, 1) {} // Initialize component sizes to 1

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    component_size[x] += component_size[y]; // Update component size
    return (true);
  }

  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) { return component_size[find(k)]; } // Return component size directly
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const { return (cost < e.cost); }
};

struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
vector<edge1> edges;
bool killed[200000];
vector<edge2> tree[100000], g[100000];
int all, ans[200000];
set<pair<int, int>> component[100000];

void rec(int idx, int par = -1) {
  auto& u = component[idx];
  for (auto &e : g[idx]) {
    u.emplace(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto &v = component[e.to];
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
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
      cout << "-1\n";
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
    cout << ans[i] << "\n";
  }
  
  return 0;
}