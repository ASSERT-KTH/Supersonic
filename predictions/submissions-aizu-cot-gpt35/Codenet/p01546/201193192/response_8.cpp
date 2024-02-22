#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> Ary;
typedef vector<Ary> Mat;

struct Edge {
    int to, c;
};

void maxUpdate(int &a, int b) {
    a = max(a, b);
}

void mul(Mat &res, Mat &a, Mat &b) {
    int N = a.size();
    res = a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (a[i][k] >= 0 && b[k][j] >= 0) {
                    maxUpdate(res[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
}

int V, K, E;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dp, prv;

void restore(int step, int v) {
    int c = step;
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = prv[c--][v];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < step + 1; ++i) {
        cout << path[i] << (i < step ? " " : "\n");
    }
}

bool shortPhase() {
    dp.assign(155, vector<int>(155, -1));
    prv.assign(155, vector<int>(155, -1));
    dp[0][0] = 0;
    int max_score = -1, step = -1, terminal = -1;
    for (int i = 0; i < 150; ++i) {
        for (int v = 0; v < V; ++v) {
            if (dp[i][v] == -1) {
                continue;
            }
            for (auto e : adj[v]) {
                if (dp[i + 1][e.first] < dp[i][v] + e.second) {
                    dp[i + 1][e.first] = dp[i][v] + e.second;
                    prv[i + 1][e.first] = v;
                    if (max_score < dp[i + 1][e.first]) {
                        max_score = dp[i + 1][e.first];
                        terminal = e.first;
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
        cout << step << endl;
        restore(step, terminal);
        return true;
    }
    if (max_score == -1) {
        cout << -1 << endl;
        return true;
    }
    return false;
}

int calcMinStep() {
    Mat mat[21], ini(V, Ary(V, -1));
    for (int v = 0; v < V; ++v) {
        for (auto e : adj[v]) {
            maxUpdate(ini[v][e.first], e.second);
        }
    }
    mat[0] = ini;
    for (int i = 0; i < 20; ++i) {
        mul(mat[i + 1], mat[i], mat[i]);
    }
    int res = 0;
    Mat x(V, Ary(V, -1)), nx;
    for (int v = 0; v < V; ++v) {
        x[v][v] = 0;
    }
    for (int h = 19; h >= 0; --h) {
        mul(nx, x, mat[h]);
        int max_score = 0;
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                maxUpdate(max_score, nx[u][v]);
            }
        }
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
        cout << (ans > (int)1e6 ? -1 : ans) << endl;
    }
}

int main() {
    cin >> V >> E >> K;
    adj.assign(V, vector<pair<int, int>>());
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
    }
    solve();
    return 0;
}