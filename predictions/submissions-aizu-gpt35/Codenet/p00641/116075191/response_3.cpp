#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 100100, MOD = 10007;

int n, b[2][MAX_N], f[2][MAX_N];
bool v[MAX_N];
vector<int> g[MAX_N];
int dp[MAX_N][2];

int dfs(int now, int maxi, int num) {
    v[now] = true;
    for (int i = 0; i < (int)g[now].size(); i++) {
        int to = g[now][i];
        if (!v[to]) {
            if (maxi == dp[to][0])
                num++;
            else if (maxi < dp[to][0]) {
                maxi = dp[to][0];
                num = 1;
            }
            if (to == 0)
                return num;
            return dfs(to, maxi, num);
        }
    }
    if (maxi == dp[0][1])
        return num + 1;
    else if (maxi < dp[0][1])
        return 1;
    else
        return num;
}

int main() {
    while (cin >> n, n) {
        memset(v, false, sizeof(v));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            b[0][i]--, b[1][i]--;
            g[b[0][i]].push_back(i);
            g[b[1][i]].push_back(i);
        }
        dp[0][0] = dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int to = b[j][i];
                int val = f[j][i];
                if (dp[i][0] + val > dp[to][0]) {
                    dp[to][1] = dp[to][0];
                    dp[to][0] = dp[i][0] + val;
                } else if (dp[i][0] + val > dp[to][1]) {
                    dp[to][1] = dp[i][0] + val;
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                ans = (ans * dfs(i, dp[i][0], 1)) % MOD;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
    }
    return 0;
}