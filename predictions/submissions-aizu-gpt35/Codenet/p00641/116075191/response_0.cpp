#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e5+5, MOD = 10007;
int n, b[2][MAXN], f[2][MAXN], ans;
bool v[MAXN];
vector<int> adj[MAXN];
int dp[MAXN][2], mx[MAXN][2], cnt[MAXN][2];

void dfs(int u) {
    v[u] = true;
    dp[u][0] = dp[u][1] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!v[v]) {
            dfs(v);
            if (mx[v][0] == mx[u][0]) {
                dp[u][0] += dp[v][0];
            } else if (mx[v][0] > mx[u][0]) {
                mx[u][0] = mx[v][0];
                dp[u][0] = dp[v][0];
            }
            if (mx[v][1] == mx[u][1]) {
                dp[u][1] += dp[v][1];
            } else if (mx[v][1] > mx[u][1]) {
                mx[u][1] = mx[v][1];
                dp[u][1] = dp[v][1];
            }
        }
    }
    if (mx[u][0] == mx[u][1]) {
        ans = (ans * (dp[u][0] + dp[u][1] - 1) % MOD) % MOD;
    } else if (mx[u][0] > mx[u][1]) {
        ans = (ans * dp[u][0]) % MOD;
    } else {
        ans = (ans * dp[u][1]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            v[i] = false;
            adj[i].clear();
            mx[i][0] = mx[i][1] = f[1][i];
            cnt[i][0] = cnt[i][1] = 1;
        }
        for (int i = 0; i < n; i++) {
            adj[b[0][i]].push_back(i);
            adj[b[1][i]].push_back(i);
        }
        ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                dfs(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}