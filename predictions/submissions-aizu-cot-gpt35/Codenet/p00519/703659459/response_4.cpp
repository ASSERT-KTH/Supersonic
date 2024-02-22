#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> pass;
vector<int> c, r, d;
vector<bool> used;

void dfs(int v, int u, int f, int end, vector<bool>& visited) {
    if (visited[u])
        return;
    visited[u] = true;
    d[u] = min(d[u], d[v] + c[v]);
    if (f >= end)
        return;
    for (int i : pass[u]) {
        dfs(v, i, f + 1, end, visited);
    }
}

int dijk(int s, int g) {
    d.assign(pass.size(), INT_MAX);
    used.assign(pass.size(), false);
    d[s] = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < pass.size(); u++) {
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if (v == -1)
            break;
        used[v] = true;
        for (int i : pass[v]) {
            vector<bool> visited(pass.size(), false);
            dfs(v, i, 1, r[v], visited);
        }
    }
    return d[g];
}

int main() {
    int n, k;
    cin >> n >> k;
    c.resize(n);
    r.resize(n);
    pass.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    cout << dijk(0, n - 1) << endl;
}