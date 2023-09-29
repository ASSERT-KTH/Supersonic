#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)

struct Edge {
    int to, c;
};

int V, K, E, dp[155][155], prv[155][155];
std::vector<std::vector<Edge>> adj;

void maxUpdate(int &a, int b) { 
    a = std::max(a, b); 
}

void restore(int step, int v) {
    int c = step;
    std::vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = prv[c--][v];
    }
    std::reverse(path.begin(), path.end());
    for_(i, 0, step + 1) std::cout << path[i] << (i < step ? " " : "\n");
}

bool shortPhase() {
    std::memset(dp, -1, sizeof(dp));
    std::memset(prv, -1, sizeof(prv));
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
            step = i + 1;
            break;
        }
    }
    if (max_score >= K) {
        std::cout << step << std::endl;
        restore(step, terminal);
        return true;
    }
    if (max_score == -1) {
        std::cout << -1 << std::endl;
        return true;
    }
    return false;
}

int calcMinStep() {
    std::vector<std::vector<int>> mat[21], ini(V, std::vector<int>(V, -1));
    for_(v, 0, V) for (Edge e : adj[v]) { maxUpdate(ini[v][e.to], e.c); }
    mat[0] = ini;
    for_(i, 0, 20) mat[i + 1] = mat[i];
    int res = 0;
    std::vector<std::vector<int>> x(V, std::vector<int>(V, -1)), nx;
    for_(v, 0, V) x[v][v] = 0;
    for_rev(h, 19, 0) {
        nx = x;
        int max_score = 0;
        for_(u, 0, V) for_(v, 0, V) maxUpdate(max_score, nx[u][v]);
        if (max_score < K) {
            x = nx;
            res += 1 << h;
        }
    }
    return res + 1;
}

void solve() {
    if (!shortPhase()) {
        int ans = calcMinStep();
        std::cout << (ans > (int)1e6 ? -1 : ans) << std::endl;
    }
}

int main() {
    std::cin >> V >> E >> K;
    adj.assign(V, std::vector<Edge>());
    for_(i, 0, E) {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[u].push_back(Edge{v, c});
    }
    solve();
}