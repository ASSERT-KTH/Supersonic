#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class HeavyLight {
    vector<vector<int>> adj, segtree;
    vector<int> size, parent, in, out, path, pathPos, pathRoot;
    int n, pathCount, time;

    void dfs(int u, int p) {
        in[u] = time++;
        parent[u] = p;
        size[u] = 1;
        for (int& v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            size[u] += size[v];
            if (size[v] > size[adj[u][0]]) swap(v, adj[u][0]);
        }
        out[u] = time++;
    }

    void hld(int u, int p) {
        path[u] = pathCount;
        pathPos[u] = pathRoot[pathCount].size();
        pathRoot[pathCount].push_back(u);
        for (int v : adj[u]) {
            if (v == p) continue;
            if (v == adj[u][0]) hld(v, u);
            else {
                pathRoot.push_back(vector<int>());
                hld(v, u);
                pathCount++;
            }
        }
    }

    bool isAncestor(int u, int v) const {
        return in[u] <= in[v] && in[v] <= out[u];
    }

public:
    HeavyLight(const vector<vector<int>>& tree) : adj(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n), pathPos(n), time(0), pathCount(0) {
        dfs(0, -1);
        pathRoot.push_back(vector<int>());
        hld(0, -1);
    }

    int lca(int u, int v) const {
        while (path[u] != path[v]) {
            if (in[pathRoot[path[u]].back()] > in[pathRoot[path[v]].back()]) swap(u, v);
            v = parent[pathRoot[path[v]].front()];
        }
        return in[u] < in[v] ? u : v;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tree[i].resize(k);
        for (int j = 0; j < k; j++) cin >> tree[i][j];
    }

    HeavyLight hld(tree);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << "\n";
    }
}