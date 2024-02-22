#include <iostream>
using namespace std;

int dp[1000005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        fill(dp, dp + n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            for (int k = 4; k >= 1; k--) {
                for (int j = n; j >= square; j--) {
                    dp[j] += dp[j - square];
                }
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}