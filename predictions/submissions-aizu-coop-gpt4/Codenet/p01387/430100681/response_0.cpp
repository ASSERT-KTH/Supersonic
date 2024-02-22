#include <bits/stdc++.h>
using namespace std;

// ... (Rest of the code is same)

// Function Inlining
inline int size(Node *t) { return count(t); }
inline bool empty(Node *t) { return !t; }
inline Node *makeset() { return (nullptr); }

// ... (Rest of the code is same)

// Use modern C++ features like auto and range-based for loop
void dfs(int idx, int par, OrderedMultiSet<int>::Node *par_set) {
  parent[idx] = par;
  tree.insert_key(par_set, X[idx]);
  nodes[idx] = par_set;
  for (auto to : g[idx])
    if (to != par)
      dfs(to, idx, par_set);
}

// ... (Rest of the code is same)

// Avoid redundant computations and use auto
auto sum = [&](int v) {
  int ret = 0;
  ret += tree.upper_bound(nodes[x], vs[v]);
  ret += tree.upper_bound(nodes[y], vs[v]);
  ret -= tree.upper_bound(nodes[lca], vs[v]);
  if (lca)
    ret -= tree.upper_bound(nodes[parent[lca]], vs[v]);
  return ret;
};

while (ok - ng > 1) {
  auto mid = (ok + ng) >> 1;
  auto sum_mid = sum(mid);
  if (sum_mid >= z)
    ok = mid;
  else
    ng = mid;
}

// ... (Rest of the code is same)
