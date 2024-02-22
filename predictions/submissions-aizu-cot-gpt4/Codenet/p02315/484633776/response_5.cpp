#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    int value[N], weight[N];
    for (int i = 0; i < N; i++)
        cin >> value[i] >> weight[i];
    int dp[2][10010] = {0};
    for (int i = 0; i < N; i++) {
        for (int w = weight[i]; w <= W; w++) {
            dp[(i+1)%2][w] = max(dp[i%2][w - weight[i]] + value[i], dp[i%2][w]);
        }
        for (int w = 0; w < weight[i]; w++) {
            dp[(i+1)%2][w] = dp[i%2][w];
        }
    }
    cout << dp[N%2][W] << endl;
    return 0;
}