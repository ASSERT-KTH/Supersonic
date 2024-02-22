#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp_cur[10001][202], dp_nxt[10001][202];

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> w[i];
    memset(dp_cur, 0, sizeof(dp_cur));
    memset(dp_nxt, 0, sizeof(dp_nxt));
    for (int j = 0; j <= W; j++) {
        for (int k = 0; k <= N; k++) {
            if (j <= W && (k == N || w[k] + j > W))
                dp_cur[j][k] = 1;
            else
                dp_cur[j][k] = 0;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            for (int k = 0; k <= N; k++) {
                dp_nxt[j][k] = dp_cur[j][k];
                int nmwidx = k;
                if (k == N || w[k] > w[i])
                    nmwidx = i;
                dp_nxt[j][k] += dp_cur[j][nmwidx];
                if (j + w[i] <= W)
                    dp_nxt[j + w[i]][k] += dp_cur[j][k];
                if (dp_nxt[j][k] >= mod)
                    dp_nxt[j][k] %= mod;
            }
            if (j + w[i] > W)
                break;
        }
        memcpy(dp_cur, dp_nxt, sizeof(dp_cur));  // copy dp_nxt to dp_cur
        memset(dp_nxt, 0, sizeof(dp_nxt));  // reset dp_nxt
    }
    cout << dp_cur[0][N] << endl;
    return 0;
}