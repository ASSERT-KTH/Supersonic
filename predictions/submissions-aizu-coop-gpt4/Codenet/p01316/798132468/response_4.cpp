#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define r(i, n) for (int i = 0; i < n; i++)

const int INF = 100000000;
vector<vector<int>> dp(20001, vector<int>(256, INF));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n) {
        vector<int> b(m);
        vector<int> a(n + 1);
        r(i, m) cin >> b[i];
        r(i, n) cin >> a[i + 1];
        
        dp[0][128] = 1;
        r(i, n) r(j, 256) if (dp[i][j] != INF) {
            r(k, m) {
                int p = j + b[k];
                p = min(max(p, 0), 255);
                int diff = a[i + 1] - p;
                int cost = diff * diff;
                if(dp[i + 1][p] > dp[i][j] + cost)
                    dp[i + 1][p] = dp[i][j] + cost;
            }
        }
        int p = INF;
        r(i, 256) if (dp[n][i] != INF) p = min(p, dp[n][i]);
        cout << p - 1 << "\n";
    }

    return 0;
}