#include <iostream>
#include <cstring>
using namespace std;

#define INF 100000000
int dp[20001][256];
int b[101];

int main() {
    int n, m;
    while (cin >> n >> m, n) {
        int a[n + 1];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][128] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] != INF) {
                    for (int k = 0; k < m; k++) {
                        int p = j + b[k];
                        if (p > 255) p = 255;
                        if (p < 0) p = 0;
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 256; i++) ans = min(ans, dp[n][i]);
        cout << ans - 1 << endl;
    }
    return 0;
}