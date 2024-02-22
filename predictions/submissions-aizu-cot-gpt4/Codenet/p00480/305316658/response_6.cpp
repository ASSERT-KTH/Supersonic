#include <iostream>
using namespace std;
int a[101];
long long dp[101][21];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    dp[1][a[1]] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = max(0, a[i] - 20); j <= min(20, a[i] + 20); j++) {
            if (j - a[i] >= 0)
                dp[i][j] += dp[i - 1][j - a[i]];
            if (j + a[i] <= 20)
                dp[i][j] += dp[i - 1][j + a[i]];
        }
    }
    cout << dp[N - 1][a[N]] << '\n';
    return 0;
}