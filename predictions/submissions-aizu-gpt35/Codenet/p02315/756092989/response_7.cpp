#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 100010;
int n, W;
int weight[MAX_N], value[MAX_N];
int dp[110][10010];
int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
        }
        for (int w = weight[i] - 1; w >= 0; w--) {
            dp[i + 1][w] = dp[i][w];
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}