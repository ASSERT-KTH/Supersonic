#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 20001;
const int MAXM = 256;
int dp[MAXN][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n) {
        vector<int> b(m), a(n + 1);
        for(int &i : b) cin >> i;
        for(int i=1; i<=n; i++) cin >> a[i];

        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), INF);
        dp[0][128] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < MAXM; j++) {
                if(dp[i][j] != INF) {
                    for(auto &k : b) {
                        int p = j + k;
                        p = min(p, 255);
                        p = max(p, 0);
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
                }
            }
        }

        int p = INF;
        for(int i = 0; i < MAXM; i++) {
            if(dp[n][i] != INF) 
                p = min(p, dp[n][i]);
        }
        cout << p - 1 << "\n";
    }

    return 0;
}