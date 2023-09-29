#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100100;
const int MOD = 10007;

vector<int> adj[MAXN];
vector<int> cost[MAXN];
bool visited[MAXN];

int dfs(int s, int u, int maxi, int num) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int w = cost[u][i];
        if (!visited[v]) {
            if (maxi == w) {
                num++;
            } else if (maxi < w) {
                maxi = w;
                num = 1;
            }
            if (v == s) {
                return num;
            }
            return dfs(s, v, maxi, num);
        }
    }
    if (maxi == cost[s][0]) {
        return num + 1;
    } else if (maxi < cost[s][0]) {
        return 1;
    } else {
        return num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            int u, w, v;
            cin >> u >> w >> v >> w;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
            visited[i] = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans = (ans * dfs(i, adj[i][0], cost[i][0], 1)) % MOD;
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            cost[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}