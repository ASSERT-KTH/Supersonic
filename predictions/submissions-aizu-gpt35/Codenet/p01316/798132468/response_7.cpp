#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define MAX_M 10005
#define MAX_N 20005
#define INF 100000000
int dp[MAX_M][256];
int a[MAX_N], b[MAX_M];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n) {
        r(i, m) cin >> b[i];
        r(i, n) cin >> a[i + 1];
        r(i, m + 1) r(j, 256) dp[i][j] = INF;
        dp[0][128] = 1;
        r(i, m) r(j, 256) if (dp[i][j] != INF) r(k, m) {
            int p = j + b[k];
            if (p > 255)
                p = 255;
            if (p < 0)
                p = 0;
            dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
        }
        int p = INF;
        r(i, 256) if (dp[m][i] != INF) p = min(p, dp[m][i]);
        cout << p - 1 << '\n';
    }
    return 0;
}