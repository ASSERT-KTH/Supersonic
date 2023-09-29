#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n) {
        vector<int> b(m);
        vector<int> a(n + 1);
        for (auto &i : b) cin >> i;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<int>> dp(n + 1, vector<int>(256, INT_MAX));
        dp[0][128] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 256; ++j) {
                if (dp[i][j] == INT_MAX) continue;
                for (int k = 0; k < m; ++k) {
                    int p = min(max(j + b[k], 0), 255);
                    dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                }
            }
        }

        cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    }

    return 0;
}