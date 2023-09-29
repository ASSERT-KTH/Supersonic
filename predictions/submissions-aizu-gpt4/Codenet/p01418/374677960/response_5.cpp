#include <iostream>
#include <cstdio>
using namespace std;
int K;
double L, R, P, E, T, dp[2][205][205];

int main() {
    cin >> K >> L >> R >> P >> E >> T;
    int sz = R - L + 1;
    for (int i = 0; i <= sz; ++i) {
        if (T - E <= i + L && i + L <= T + E) dp[0][i][i] = 1;
    }
    for (int d = 1; d <= K; ++d) {
        int cur = d & 1, pre = cur ^ 1;
        for (int len = 0; len <= sz; ++len) {
            for (int l = 0; l + len <= sz; ++l) {
                int r = l + len;
                double mid = l + (r - l) / 2;
                if (mid >= T) dp[cur][l][r] = (1.0 - P) * dp[pre][l][mid] + P * dp[pre][mid][r];
                else dp[cur][l][r] = (1.0 - P) * dp[pre][mid][r] + P * dp[pre][l][mid];
            }
        }
    }
    printf("%.9f\n", dp[K & 1][0][sz]);
    return 0;
}