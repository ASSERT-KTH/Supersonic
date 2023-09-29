#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 333;

int dp[MAX_N][MAX_N];
int c[MAX_N], v[3][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin.ignore();
            cin.ignore();
            cin >> c[i];
            for (int j = 0; j < 3; ++j) cin >> v[j][i];
        }

        int res = 0;
        for (int i = 0; i < 3; ++i) {
            memset(dp, 0, sizeof(dp));
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= m; ++k) {
                    dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
                    if (k >= c[j])
                        dp[j + 1][k] = max(dp[j + 1][k], dp[j + 1][k - c[j]] + v[i][j]);
                }
            }
            res = max(res, dp[n][m]);
        }

        cout << res << '\n';
    }
    return 0;
}