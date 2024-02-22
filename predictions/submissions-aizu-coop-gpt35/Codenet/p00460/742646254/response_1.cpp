#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int const MOD = 100000;

int main() {
    int const MAX_N = 55;
    int const MAX_S = 3030;
    int dp[MAX_N * MAX_N + 1][MAX_S + 1];

    int N, M, S;
    while (cin >> N >> M >> S && (N | M | S)) {
        // Clear dp array
        memset(dp, 0, sizeof dp);

        dp[0][0] = 1;

        for (int add = 1; add <= M; add++) {
            for (int currIndex = N * N; currIndex >= 1; currIndex--) {
                for (int currSum = add; currSum <= S; currSum++) {
                    int prevSum = currSum - add;
                    dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][prevSum]) % MOD;
                }
            }
        }

        cout << dp[N * N][S] << endl;
    }

    return 0;
}