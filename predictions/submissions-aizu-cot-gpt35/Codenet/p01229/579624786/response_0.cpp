#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N);
      for (int i = 0; i < N; i++) {
        cin >> input[i];
      }
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      vector<vector<bool>> dp(N, vector<bool>(N));
      for (int cur = 1; cur < N - 1; cur++) {
        dp[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        for (int L = 1; L < N; L++) {
          for (int M = 1; M < N; M++) {
            if (!dp[L][M]) {
              continue;
            }
            if (M == 1) {
              if (cur + 2 < N) {
                dp[M][R] = true;
              } else {
                ans = max(ans, R);
              }
            } else {
              if (cur + 2 < N) {
                dp[M][R] = true;
                dp[M - 1][R + L] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}