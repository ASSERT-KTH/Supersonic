#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 110;
const int MAXW = 10010;

int N, W;
int value[MAXN], weight[MAXN];
int dp[MAXW];

int main() {
    cin >> N >> W;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        cin >> value[i] >> weight[i];
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}