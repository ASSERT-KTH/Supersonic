#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

void dfs(int u, int depth, int& path_size, vector<int>& idx_in_path, vector<ii>& path, const vector<vi>& adjList) {
    idx_in_path[u] = path_size;
    path.emplace_back(depth, u);
    path_size++;
    for (int v : adjList[u]) {
        dfs(v, depth + 1, path_size, idx_in_path, path, adjList);
        path.emplace_back(depth, u);
        path_size++;
    }
}

void build_sparse_table(int n, const vector<ii>& path, vector<vector<ii>>& ST) {
    int h = ceil(log2(n + 1));
    for (int i = 0; i < n; i++) {
        ST[0][i] = path[i];
    }
    for (int i = 1; i < h; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int lca(int u, int v, const vector<int>& idx_in_path, const vector<vector<ii>>& ST) {
    int l = idx_in_path[u], r = idx_in_path[v];
    if (l > r)
        swap(l, r);
    r++;
    int p = 31 - __builtin_clz(r - l);
    return min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
    int num_nodes;
    cin >> num_nodes;

    vector<vi> adjList(num_nodes);
    for (int u = 0; u < num_nodes; u++) {
        int num_neighbors;
        cin >> num_neighbors;
        adjList[u].reserve(num_neighbors);
        for (int i = 0; i < num_neighbors; i++) {
            int v;
            cin >> v;
            adjList[u].emplace_back(v);
        }
    }

    vector<int> idx_in_path(num_nodes);
    vector<ii> path;
    int path_size = 0;
    dfs(0, 0, path_size, idx_in_path, path, adjList);

    int n = path_size;
    int h = ceil(log2(n + 1));
    vector<vector<ii>> ST(h, vector<ii>(n));

    build_sparse_table(n, path, ST);

    int num_queries;
    cin >> num_queries;

    for (int i = 0; i < num_queries; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, idx_in_path, ST) << endl;
    }

    return 0;
}