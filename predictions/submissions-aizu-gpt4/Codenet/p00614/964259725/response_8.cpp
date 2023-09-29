#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define int long long
using namespace std;

int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[2][T];

int calc(int v) {
    int ans = 0;
    for (int i = 5; i >= 0; i--) {
      int t = min(v / C[i], N[i]);
      v -= t * C[i];
      ans += t;
    }
    return v == 0 ? ans : 1e9;
}

signed main() {
    while (cin >> P) {
        for (int& n : N) cin >> n;
        if (P == 0) break;
        fill_n(*dp, 2 * T, 1e9);
        dp[0][0] = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < T; j++) {
                dp[(i + 1) & 1][j] = dp[i & 1][j];
                if (j >= C[i] && dp[i & 1][j - C[i]] != 1e9) {
                    dp[(i + 1) & 1][j] = min(dp[(i + 1) & 1][j], dp[i & 1][j - C[i]] + 1);
                }
            }
        }
        cout << dp[1][P] << endl;
    }
    return 0;
}