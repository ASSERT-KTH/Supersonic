#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    int value[N], weight[N];
    for (int i = 0; i < N; i++)
        cin >> value[i] >> weight[i];

    int dp[N+1][W+1] = {0};

    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i==0 || w==0)
                dp[i][w] = 0;
            else if (w >= weight[i-1])
                dp[i][w] = max(dp[i-1][w - weight[i-1]] + value[i-1], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}