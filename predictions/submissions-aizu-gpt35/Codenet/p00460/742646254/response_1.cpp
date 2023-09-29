#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 100000;
const int MAX_N = 55;
const int MAX_S = 3030;

int dp[MAX_N * MAX_N][MAX_S];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S;
    while (cin >> N >> M >> S && (N | M | S)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int add = 1; add <= M; ++add) {
            for (int currIndex = N * N; currIndex >= 1; --currIndex) {
                for (int currSum = S; currSum >= add; --currSum) {
                    dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
                    if (dp[currIndex][currSum] >= MOD) {
                        dp[currIndex][currSum] -= MOD;
                    }
                }
            }
        }
        cout << dp[N * N][S] << '\n';
    }

    return 0;
}