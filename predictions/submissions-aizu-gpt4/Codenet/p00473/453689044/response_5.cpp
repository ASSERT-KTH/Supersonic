#include <cstdio>
#include <cstring>
using namespace std;

constexpr int MAX_N = 5002;
int t[MAX_N * 2];
int dp[MAX_N][2];

int minCost(const int a, const int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return a < b ? a : b;
}

int solve(int n) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i / 2; j >= 0; j--) {
            for (int pre = 0; pre < 2; pre++) {
                if (dp[j][pre] == -1)
                    continue;
                for (int next = 0; next < 2; next++) {
                    const int cost = (pre == next) ? 0 : t[i-1];
                    const int new_cost = dp[j][pre] + cost;
                    if (next == 0 && j + 1 <= n / 2)
                        dp[j + 1][next] = minCost(dp[j + 1][next], new_cost);
                    else
                        dp[j][next] = minCost(dp[j][next], new_cost);
                }
            }
        }
    }
    return minCost(dp[n / 2][0], dp[n / 2][1]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &t[i]);
    }
    printf("%d\n", solve(n));
}