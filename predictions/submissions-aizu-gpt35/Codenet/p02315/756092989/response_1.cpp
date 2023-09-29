#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, W;
vector<int> weight(110), value(110);
vector<vector<int>> dp(110, vector<int>(10010, 0));

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
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