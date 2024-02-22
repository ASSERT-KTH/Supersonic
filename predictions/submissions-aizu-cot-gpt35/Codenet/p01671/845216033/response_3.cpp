#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using int64 = long long;

struct UnionFind {
  int *data;
  UnionFind(int sz) {
    data = new int[sz];
    for (int i = 0; i < sz; i++) {
      data[i] = -1;
    }
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
  int size(int k) { return -data[find(k)]; }
};

struct edge1 {
  int u, v, cost, idx;
  bool operator<(const edge1 &e) const { return cost < e.cost; }
};

struct edge2 {
  int to, cost, idx;
};

int N, M, A[200000], B[200000], C[200000];
vector<edge1> edges;
bool killed[200000];
vector<edge2> tree[100000], g[100000];
int64 all, ans[200000];
pair<int, int> component[100000];

void rec(int idx, int par = -1) {
  for (auto &e : g[idx]) {
    component[idx] = make_pair(e.cost, e.idx);
  }
  for (auto &e : tree[idx]) {
    if (e.to == par)
      continue;
    rec(e.to, idx);
    auto &u = component[idx], &v = component[e.to];
    if (v.first != -1) {
      ans[e.idx] = all;
      ans[e.idx] -= e.cost;
      ans[e.idx] += v.first;
    }
    if (u.second.size() < v.second.size())
      swap(u, v);
    while (v.second.size() > 0) {
      auto it = v.second.begin();
      if (u.second.count(*it))
        u.second.erase(*it);
      else
        u.second.insert(*it);
      v.second.erase(it);
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
      cout << -1 << endl;
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
    cout << ans[i] << endl;
  }
  return 0;
}