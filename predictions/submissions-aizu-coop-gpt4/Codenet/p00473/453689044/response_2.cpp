#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int t[10002];
vector<pair<int, int>> dp(5002, {-1, -1});
vector<pair<int, int>> tmp(5002, {-1, -1});

int solve() {
    tmp[1].first = tmp[0].second = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n / 2; j++) {
            pair<int, int> &cur = tmp[j];
            if (cur.first == -1 && cur.second == -1)
                continue;
            int cost = cur.first != -1 ? cur.first + t[i - 1] : cur.second + t[i - 1];
            dp[j + 1].first = (cur.first != -1) ? min(dp[j + 1].first, cost) : dp[j + 1].first;
            dp[j].second = (cur.second != -1) ? min(dp[j].second, cost) : dp[j].second;
        }
        tmp = dp;
    }
    return min(dp[n / 2].first, dp[n / 2].second);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &t[i]);
    }
    printf("%d\n", solve());
    return 0;
}