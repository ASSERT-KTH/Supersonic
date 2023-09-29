#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20001;
const int MAXM = 256;
const int INF = 1e8;

int dp[MAXN][MAXM];
int b[MAXM], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n) {
        for (int i = 0; i < m; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][128] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < MAXM; ++j) {
                if (dp[i][j] == INF) continue;
                for (int k = 0; k < m; ++k) {
                    int p = j + b[k];
                    if (p > 255) p = 255;
                    if (p < 0) p = 0;
                    dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < MAXM; ++i) ans = min(ans, dp[n][i]);
        cout << ans - 1 << "\n";
    }

    return 0;
}