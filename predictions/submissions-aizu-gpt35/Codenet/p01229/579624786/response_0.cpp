#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 150
using namespace std;

bool dp[MAX][MAX][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    int input[N];
    for (int i = 0; i < N; i++) cin >> input[i];

    if (N <= 2) {
      cout << input[N - 1] << '\n';
      continue;
    }

    int ans = input[N - 1];
    for (int cur = 1; cur < N - 1; cur++) {
      for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
          dp[i][j][cur & 1] = false;
        }

      dp[input[cur - 1]][input[cur]][cur & 1] = true;
      int R = input[cur + 1];

      for (int L = 0; L < MAX; L++) {
        for (int M = 0; M < MAX; M++) {
          if (!dp[L][M][cur & 1]) continue;

          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
            } else {
              ans = max(ans, R);
            }
          } else {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
              dp[M - 1][R + L][(cur + 1) & 1] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}