#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MOD = 100000;
    vector<vector<int>> dp(55, vector<int>(3030, 0));

    int N, M, S;
    while (cin >> N >> M >> S && (N | M | S)) {
        for (int i = 0; i < 55; ++i) {
            fill(dp[i].begin(), dp[i].end(), 0);
        }
        dp[0][0] = 1;

        for (int add = 1; add <= M; ++add) {
            for (int currIndex = N * N; currIndex >= 1; --currIndex) {
                for (int currSum = max(add, currIndex*add); currSum <= S; ++currSum) {
                    (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
                }
            }
        }
        cout << dp[N * N][S] << '\n';
    }
    return 0;
}