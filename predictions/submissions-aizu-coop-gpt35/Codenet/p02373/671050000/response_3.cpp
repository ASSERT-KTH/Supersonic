#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;

struct HeavyLight {
  vector<vector<int>> tree;
  int n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  vector<vector<int>> len;

  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    computeLen();
  }

  void dfs(int u, int p, int &k) {
    in[u] = k++;
    parent[u] = p;
    size[u] = 1;
    EACH(v, tree[u]) if (*v != p) dfs(*v, u, k), size[u] += size[*v];
    out[u] = k++;
  }

  void computeLen() {
    len = vector<vector<int>>(n);
    REP(i, n) {
      len[i].resize(2 * pathSize[i]);
      fill(ALL(len[i]), 0);
    }

    REP(u, n) {
      int pt = path[u];
      int pos = pathPos[u];
      len[pt][pos] = 1;

      int v = parent[u];
      if (v != -1) {
        int root = pathRoot[pt];
        int rootPos = pathPos[root];
        int lenPos = rootPos + 2 * size[v] - size[root];

        while (root != -1) {
          if (rootPos <= lenPos && lenPos < rootPos + pathSize[root]) {
            len[root][lenPos] = 1;
            break;
          }
          root = parent[root];
          if (root != -1) {
            rootPos = pathPos[root];
            lenPos = rootPos + 2 * size[v] - size[root];
          }
        }
      }
    }
  }

  // Rest of the code remains the same...
};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  REP(i, n) {
    int k;
    cin >> k;
    REP(j, k) {
      int ch;
      cin >> ch;
      tree[i].push_back(ch);
    }
  }
  HeavyLight hl = HeavyLight(tree);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}