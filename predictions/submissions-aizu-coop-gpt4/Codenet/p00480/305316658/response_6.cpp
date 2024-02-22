#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[110][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(long long), 0);

    int temp;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &temp);
        dp[i][temp] = i == 1 ? 1 : dp[i - 1][temp - 1] + dp[i - 1][temp + 1];
    }

    printf("%lld\n", dp[N - 1][temp]);

    return 0;
}