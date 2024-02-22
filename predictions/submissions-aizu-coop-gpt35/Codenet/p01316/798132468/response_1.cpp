#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n) {
        vector<int> b(m);
        vector<int> a(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(256, 100000000));
        dp[0][128] = 1;
        
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] != 100000000) {
                    for (int k = 0; k < m; k++) {
                        int p = j + b[k];
                        if (p > 255) {
                            p = 255;
                        }
                        if (p < 0) {
                            p = 0;
                        }
                        int cost = dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p);
                        if (cost < dp[i + 1][p]) {
                            dp[i + 1][p] = cost;
                        }
                    }
                }
            }
        }

        int minCost = 100000000;
        for (int i = 0; i < 256; i++) {
            if (dp[n][i] != 100000000) {
                if (dp[n][i] < minCost) {
                    minCost = dp[n][i];
                }
            }
        }

        cout << minCost - 1 << endl;
    }

    return 0;
}