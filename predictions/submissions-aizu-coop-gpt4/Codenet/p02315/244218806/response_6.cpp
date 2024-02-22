#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> v[i] >> w[i];
    
    vector<int> dp(W+1, 0);  // 1D DP table, initialized to 0

    for (int i = 0; i < N; i++) {
        for (int j = W; j >= w[i]; j--) {  // reverse order
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;
    return 0;
}