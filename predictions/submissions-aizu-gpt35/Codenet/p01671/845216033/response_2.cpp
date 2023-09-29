#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

const int MAXN = 100000, MAXM = 200000;

int N, M, A[MAXM], B[MAXM], C[MAXM], all;
int64 ans[MAXM];
bool killed[MAXM];

vector<int> g[MAXN], tree[MAXN];
set<pair<int, int>> component[MAXN];

int parent[MAXN], size[MAXN];
int find(int x) {
  return x == parent[x] ? x : parent[x] = find(parent[x]);
}
bool unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return false;
  if (size[x] < size[y]) swap(x, y);
  size[x] += size[y], parent[y] = x;
  return true;
}

void dfs(int u, int p = -1) {
  for (const int &v : g[u])
    component[u].emplace(C[v], v);
  for (const int &v : tree[u]) {
    dfs(v, u);
    auto &u_set = component[u], &v_set = component[v];
    if (v_set.empty()) continue;
    ans[v_set.begin()->second] = all - v_set.begin()->first;
    if (u_set.size() < v_set.size()) swap(u_set, v_set);
    while (!v_set.empty()) {
      const auto p = v_set.begin();
      if (u_set.count(*p)) u_set.erase(*p);
      else u_set.emplace(*p);
      v_set.erase(p);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  iota(parent, parent + N, 0), fill(size, size + N, 1);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
  }
  vector<int> idx(M);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [](const int &lhs, const int &rhs) {
    return C[lhs] < C[rhs];
  });
  for (const int &i : idx) {
    if (unite(A[i], B[i])) {
      killed[i] = true;
      all += C[i];
    }
  }
  if (size[find(0)] != N) {
    for (int i = 0; i < M; i++) puts("-1");
    return 0;
  }
  for (int i = 0; i < M; i++) {
    if (killed[i]) {
      tree[A[i]].push_back(i);
      tree[B[i]].push_back(i);
    } else {
      g[A[i]].push_back(i);
      g[B[i]].push_back(i);
      ans[i] = all;
    }
  }
  dfs(0);
  for (int i = 0; i < M; i++) printf("%lld\n", ans[i]);
}