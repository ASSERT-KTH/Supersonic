#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> input(N);
    for (int &num : input)
      cin >> num;

    if (N <= 2) {
      cout << input[N - 1] << endl;
      continue;
    }

    int ans = input[N - 1];
    vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(N, vector<bool>(2, false)));
    for (int cur = 1; cur < N - 1; ++cur) {
      dp[input[cur - 1]][input[cur]][cur & 1] = true;
      int R = input[cur + 1];
      for (int L = 0; L <= cur; ++L) {
        for (int M = 0; M <= cur; ++M) {
          if (!dp[L][M][cur & 1])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
            } else
              ans = max(ans, R);
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
    cout << ans << endl;
  }
  return 0;
}