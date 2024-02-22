#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int d;
};

using Graph = vector<vector<Edge>>;

struct LowestCommonAncestor {
    const int n;
    int log2_n;
    vector<int> parent;
    vector<int> depth;

    LowestCommonAncestor(const Graph& g, int root)
        : n(g.size()), parent(n), depth(n)
    {
        log2_n = log2(n) + 1;
        dfs(g, root, -1, 0);
        constructParentArray();
    }

    void dfs(const Graph& g, int s, int p, int d) {
        parent[s] = p;
        depth[s] = d;
        for (const auto& e : g[s]) {
            if (e.d == p) {
                continue;
            }
            dfs(g, e.d, s, d + 1);
        }
    }

    void constructParentArray() {
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[v] < 0) {
                    parent[v] = -1;
                }
                else {
                    parent[v] = parent[parent[v]];
                }
            }
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[v];
            }
        }
        if (u == v) {
            return u;
        }
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[u] != parent[v]) {
                u = parent[u];
                v = parent[v];
            }
        }
        return parent[u];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            g[i][j].d = c;
        }
    }

    int q;
    cin >> q;

    LowestCommonAncestor lca(g, 0);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.get(u, v) << endl;
    }

    return 0;
}