#include <iostream>
#include <climits>
using namespace std;

const int M = 10;

void mainFunction() {
    int k;
    while (cin >> k, k) {
        string s, t;
        cin >> s >> t;

        int dp[k+1][M];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < M; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[k][0] = 0;

        for (int p = k-1; p >= 0; p--) {
            for (int d = 0; d < M; d++) {
                int rot = ((int)(t[p] - s[p]) + M) % M;
                int new_dif[k];
                for (int i = p; i < k; i++) {
                    new_dif[i] = (dp[p+1][d] + d) % M;
                }

                for (int i = p; i < k; i++) {
                    new_dif[i] = (new_dif[i] - rot + M) % M;
                    dp[p][d] = min(dp[p][d], dp[p+1][new_dif[i]] + 1);
                    new_dif[i] = (new_dif[i] + rot) % M;
                }
            }
        }

        cout << dp[0][0] << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}