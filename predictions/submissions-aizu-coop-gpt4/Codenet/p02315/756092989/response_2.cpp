#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    int weight[110], value[110];
    int dp[10010] = {0};

    for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}