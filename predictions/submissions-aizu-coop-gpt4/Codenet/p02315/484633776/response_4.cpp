#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    int value[N], weight[N];
  
    for (int i = 0; i < N; i++)
        cin >> value[i] >> weight[i];
  
    int dp[110][10010] = {};
  
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < N; i++) {
            if (w >= weight[i]) {
                int newValue = dp[i][w - weight[i]] + value[i];
                dp[i + 1][w] = (newValue > dp[i][w]) ? newValue : dp[i][w];
            } else {
                dp[i + 1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}