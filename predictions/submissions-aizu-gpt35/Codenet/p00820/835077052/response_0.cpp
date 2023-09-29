#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000000 + 7;

int n;
int dp[N];

void solve() {
    while (scanf("%d", &n) == 1) {
        if (n == 0) return;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] += dp[j - i * i];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] != 0 && i <= 4) {
                ans += dp[i];
            }
            for (int j = 4; j >= 2; j--) {
                if (dp[i] != 0 && i - j * j >= 0) {
                    ans += dp[i - j * j];
                }
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    solve();
    return 0;
}