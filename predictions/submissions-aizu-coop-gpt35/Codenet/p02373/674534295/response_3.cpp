#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Edge {
    int s, d;
    Edge(int s, int d) : s(s), d(d) {};
};

class LowestCommonAncestor {
public:
    LowestCommonAncestor(const vector<vector<int>>& graph, int root) : graph(graph) {
        int n = graph.size();
        log2_n = log2(n) + 1;
        parent.resize(n, -1);
        dfs(root, -1);
        computeBinaryLifting();
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];
        for (int k = 0; k < log2_n; k++) {
            if (diff & (1 << k)) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

private:
    const vector<vector<int>>& graph;
    int log2_n;
    vector<vector<int>> parent;
    vector<int> depth;

    void dfs(int node, int parent_node) {
        parent[0][node] = parent_node;
        depth[node] = parent_node == -1 ? 0 : depth[parent_node] + 1;
        for (int child : graph[node]) {
            if (child == parent_node) continue;
            dfs(child, node);
        }
    }

    void computeBinaryLifting() {
        int n = graph.size();
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[k][v] < 0) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        graph[i].reserve(k);
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            graph[i].push_back(c);
        }
    }

    int q;
    cin >> q;
    LowestCommonAncestor lca(graph, 0);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.get(u, v) << endl;
    }

    return 0;
}