#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
const int MAXW = 10001;
int dp[MAXN][MAXW];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i] >> w[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W] << '\n';
    return 0;
}