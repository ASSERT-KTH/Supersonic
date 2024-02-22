#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int t[10002];
int dp[5002][2], tmp[5002][2];

int minCost(int a, int b) {
    return min(a, b);
}

int solve() {
    memset(tmp, -1, sizeof(tmp));
    tmp[1][0] = tmp[0][1] = 0;
    int halfN = n / 2;
    for (int i = 1; i < n; i++) {
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j <= halfN; j++) {
            for (int pre = 0; pre < 2; pre++) {
                if (tmp[j][pre] != -1) {
                    for (int next = 0; next < 2; next++) {
                        int cost = (pre != next) ? tmp[j][pre] + t[i - 1] : tmp[j][pre];
                        int newJ = (next == 0) ? j + 1 : j;
                        dp[newJ][next] = minCost(dp[newJ][next], cost);
                    }
                }
            }
        }
        copy(&dp[0][0], &dp[0][0] + 5002*2, &tmp[0][0]);
    }
    return minCost(dp[halfN][0], dp[halfN][1]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> t[i];
    }
    cout << solve() << endl;
    return 0;
}