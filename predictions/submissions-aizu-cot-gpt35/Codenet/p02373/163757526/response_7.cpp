#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 100005;
const int LOGN = 20;

int idx_in_path[MAXN];
ii path[MAXN << 1];
vi adjList[MAXN];
int path_size = 0;

void dfs(int root) {
  vector<int> stack;
  stack.push_back(root);
  idx_in_path[root] = path_size;
  path[path_size++] = ii(0, root);

  while (!stack.empty()) {
    int u = stack.back();
    stack.pop_back();

    for (int v : adjList[u]) {
      idx_in_path[v] = path_size;
      path[path_size++] = ii(path[idx_in_path[u]].first + 1, v);
      stack.push_back(v);
    }
  }
}

ii ST[LOGN][MAXN << 1];

void build(int n) {
  int h = log2(n) + 1;

  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];

  int pow2[LOGN];
  pow2[0] = 1;

  for (int i = 1; i < LOGN; i++)
    pow2[i] = pow2[i - 1] * 2;

  for (int i = 1; i < h; i++) {
    int len = pow2[i];
    for (int j = 0; j + len <= n; j++) {
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + len / 2]);
    }
  }
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = log2(r - l);
  return min(ST[p][l], ST[p][r - pow(2, p)]).second;
}

int main() {
  int num_nodes;
  cin >> num_nodes;

  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    cin >> num_neighbors;

    for (int i = 0; i < num_neighbors; i++) {
      int v;
      cin >> v;
      adjList[u].push_back(v);
    }
  }

  dfs(0);
  build(path_size);

  int num_queries;
  cin >> num_queries;

  for (int i = 0; i < num_queries; i++) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }

  return 0;
}