#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i + 1][w] = dp[i][w];
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}