#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_W = 10010;
int n, W;
int weight[110], value[110];
int dp[2][MAX_W];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
  
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp[(i + 1) % 2][w] = max(dp[i % 2][w - weight[i]] + value[i], dp[i % 2][w]);
            } else {
                dp[(i + 1) % 2][w] = dp[i % 2][w];
            }
        }
    }
  
    cout << dp[n % 2][W] << endl;
    return 0;
}