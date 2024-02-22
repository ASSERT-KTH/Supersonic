#include <iostream>
#include <cstring>
#include <omp.h>

using ll = long long;
const int inf = 1 << 29;
int dp[55][3030];

template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
    return b < a && (a = b, true);
}

template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
    return a < b && (a = b, true);
}

int main() {
    const int MOD = 100000;
    int N, M, S;
    while (std::cin >> N >> M >> S && (N | M | S)) {
        std::memset(dp, 0, sizeof(dp));  // Faster array initialization
        dp[0][0] = 1;
        // Parallelize outer two loops
        #pragma omp parallel for collapse(2)
        for (int add = 1; add <= M; ++add) {
            for (int currIndex = N * N; currIndex >= 1; --currIndex) {
                for (int currSum = add; currSum <= S; ++currSum) {
                    dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
                }
            }
        }
        std::cout << dp[N * N][S] << std::endl;
    }
    return 0;
}