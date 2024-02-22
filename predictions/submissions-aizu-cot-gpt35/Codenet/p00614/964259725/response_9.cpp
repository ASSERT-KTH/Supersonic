#include <iostream>
#include <algorithm>
using namespace std;

int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[2][T];

int main() {
  while (cin >> P) {
    for (int i = 0; i < 6; i++) cin >> N[i];
    if (P == 0) break;
    fill_n(*dp, T, 1001001001);
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (N[i]) {
        if (P - C[i] >= 0) {
          cnt++;
          N[i]--;
          P -= C[i];
        } else {
          break;
        }
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          if (k >= C[i] && dp[i & 1][k - C[i]] + 1 < dp[(i + 1) & 1][k]) {
            dp[(i + 1) & 1][k] = dp[i & 1][k - C[i]] + 1;
          }
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + (i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}