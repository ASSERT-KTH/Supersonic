#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX 150
using namespace std;
unordered_map<int, bool> dp[2];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      dp[0].clear();
      dp[1].clear();
      int N;
      cin >> N;
      vector<int> input(N);
      for (int i = 0; i < N; ++i) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      for (int cur = 1; cur < N - 1; ++cur) {
        int flag = cur & 1;
        for (const auto &it : dp[flag]) {
          int L = it.first / MAX, M = it.first % MAX;
          int R = input[cur + 1];
          if (M == 0) {
            if (cur + 2 < N) {
              dp[1 - flag][M * MAX + R] = true;
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[1 - flag][M * MAX + R] = true;
              dp[1 - flag][(M - 1) * MAX + R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
        dp[flag].clear();
      }
      cout << ans << endl;
    }
  }
  return 0;
}