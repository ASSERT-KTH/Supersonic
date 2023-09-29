#include <iostream>
#include <vector>

using namespace std;
constexpr int MAX_N = 100;
constexpr int MAX_NUM = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(MAX_NUM + 1, 0));
    dp[1][a[1]] = 1;
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j <= MAX_NUM; ++j) {
            if (j - a[i] >= 0)
                dp[i][j] += dp[i - 1][j - a[i]];
            if (j + a[i] <= MAX_NUM)
                dp[i][j] += dp[i - 1][j + a[i]];
        }
    }
    cout << dp[N - 1][a[N]] << '\n';
    return 0;
}