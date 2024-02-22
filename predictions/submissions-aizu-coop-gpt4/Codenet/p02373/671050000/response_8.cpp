// Replace EACH macro with range-based for loop
for(auto &v : tree[u]) {
  if(v != p) {
    dfs(v, u, k);
    size[u] += size[v];
  }
}

// Convert dfs function to iterative
void dfs(int u, int p, int &k) {
  stack<pair<int, int>> stk;
  stk.push({u, p});
  while(!stk.empty()) {
    tie(u, p) = stk.top();
    stk.pop();
    in[u] = k++, parent[u] = p, size[u] = 1;
    for(auto &v : tree[u]) {
      if(v != p) {
        stk.push({v, u});
      }
    }
    out[u] = k++;
  }
}

// Convert buildPaths function to iterative
void buildPaths(int u, int pt) {
  stack<pair<int, int>> stk;
  stk.push({u, pt});
  while(!stk.empty()) {
    tie(u, pt) = stk.top();
    stk.pop();
    path[u] = pt, pathPos[u] = pathSize[pt]++;
    for(auto &v : tree[u]) {
      if(v != parent[u]) {
        stk.push({v, 2 * size[v] >= size[u] ? pt : newPath(v)});
      }
    }
  }
}

// Precompute ancestors to avoid redundant computation
vector<int> ancestor(n);
void precomputeAncestors() {
  for(int i = 0; i < n; i++) {
    ancestor[i] = parent[pathRoot[path[i]]];
  }
}