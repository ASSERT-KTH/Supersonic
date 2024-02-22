#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 10, INF = 1e9;
int main() {
    int k;
    while (cin >> k, k) {
        string s, t;
        cin >> s >> t;
        vector<int> dif(k);
        for (int i = 0; i < k; i++) {
            dif[i] = ((int)(t[i] - s[i]) + M) % M;
        }
        vector<vector<int>> dp(k + 1, vector<int>(2 * k * M + 1, INF));
        dp[0][k * M] = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= 2 * k * M; j++) {
                if (dp[i][j] == INF) continue;
                for (int rot = 0; rot < M; rot++) {
                    int nj = j + rot - dif[i];
                    if (nj < 0 || nj > 2 * k * M) continue;
                    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + rot);
                    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + M - rot);
                }
            }
        }
        int ans = *min_element(dp[k].begin(), dp[k].end());
        cout << ans << endl;
    }
}