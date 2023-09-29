#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define for_(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

struct Edge {
    int to, c;
};

int V, K, E, dp[155][155], prv[155][155];
vector<vector<Edge>> adj;

void restore(int step, int v) {
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = prv[step--][v];
    }
    reverse(path.begin(), path.end());
    for_(i, 0, step + 1) cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
    memset(dp, -1, sizeof(dp));
    memset(prv, -1, sizeof(prv));
    for_(v, 0, V) dp[0][v] = 0;
    int max_score = -1, step = -1, terminal = -1;
    for_(i, 0, 150) {
        for_(v, 0, V) {
            if (dp[i][v] == -1)
                continue;
            for (Edge e : adj[v]) {
                if (dp[i + 1][e.to] < dp[i][v] + e.c) {
                    dp[i + 1][e.to] = dp[i][v] + e.c;
                    prv[i + 1][e.to] = v;
                    if (max_score < dp[i + 1][e.to]) {
                        max_score = dp[i + 1][e.to];
                        terminal = e.to;
                    }
                }
            }
        }
        if (max_score >= K) {
            cout << i + 1 << "\n";
            restore(i + 1, terminal);
            return true;
        }
    }
    return false;
}

int calcMinStep() {
    vector<vector<int>> mat[21], ini(V, vector<int>(V, -1)), x(V, vector<int>(V, -1)), nx;
    for_(v, 0, V) for (Edge e : adj[v]) { ini[v][e.to] = max(ini[v][e.to], e.c); }
    mat[0] = ini;
    for_(i, 0, 20) {
        nx = x = mat[i];
        for_(j, 0, V) for_(k, 0, V) for_(l, 0, V) if (x[j][k] >= 0 && mat[i][k][l] >= 0) nx[j][l] = max(nx[j][l], x[j][k] + mat[i][k][l]);
        mat[i + 1] = nx;
    }
    for_(v, 0, V) x[v][v] = 0;
    for(int h = 19; h >= 0; --h) {
        nx = x;
        for_(i, 0, V) for_(j, 0, V) for_(k, 0, V) if (x[i][k] >= 0 && mat[h][k][j] >= 0) nx[i][j] = max(nx[i][j], x[i][k] + mat[h][k][j]);
        if (*max_element(nx[0].begin(), nx[0].end()) < K) x = nx;
        else return h + 1;
    }
    return 21;
}

void solve() {
    if (!shortPhase()) {
        int ans = calcMinStep();
        cout << (ans > 20 ? -1 : ans) << "\n";
    }
}

int main() {
    cin >> V >> E >> K;
    adj.resize(V);
    for_(i, 0, E) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(Edge{v, c});
    }
    solve();
}