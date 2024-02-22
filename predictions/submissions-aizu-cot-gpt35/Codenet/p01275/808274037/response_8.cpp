#include <iostream>
using namespace std;

const int MAX_K = 12;
const int M = 10;

int main() {
  int k;
  while (cin >> k, k) {
    char s[MAX_K], t[MAX_K];
    cin >> s >> t;

    int dif[MAX_K][MAX_K];
    for (int i = 0; i < k; i++) {
      dif[i][i] = ((int)(t[i] - s[i]) + M) % M;
      for (int j = i + 1; j < k; j++) {
        dif[i][j] = (dif[i][j - 1] + dif[j][j]) % M;
      }
    }

    int dp[MAX_K][MAX_K];
    for (int p = 0; p < k; p++) {
      dp[k][p] = 0;
    }

    for (int d = k - 1; d >= 0; d--) {
      for (int p = 0; p < k; p++) {
        if (p == k - 1) {
          dp[d][p] = d;
        } else {
          dp[d][p] = dp[d + 1][p];
          int rot = dif[p][k - 1];
          for (int i = p; i < k; i++) {
            dp[d][p] = min(dp[d][p], dp[d + 1][p + 1] + 1);
            rot = (rot - dif[p][i]) % M;
          }
          rot = (rot + M) % M;
          for (int i = p; i < k; i++) {
            dif[p][i] = (dif[p][i] + rot) % M;
          }
        }
      }
    }

    cout << dp[0][0] << endl;
  }
}